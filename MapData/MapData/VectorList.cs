using System;
using System.ServiceModel;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MapData
{
    /// <summary>
    /// A collection of vectors that surmise the surfaces on a map.
    /// you can get this either as a list of vectors or as a double array of bools, true means passable, false means impassable
    /// This will eventually be serializable to JSON
    /// </summary>
    public class Map
    {
        private readonly List<Line> _surfaces = new List<Line>();
        /// <summary>
        /// empty constructor, does nothing
        /// </summary>
        Map()
        {
        }

        /// <summary>
        /// returns the Surfaces as a list
        /// </summary>
        public List<Line> Surfaces
        {
            get
            {
                return _surfaces;
            }
        }

        /// <summary>
        /// adds a specific surface along the given lines
        /// </summary>
        /// <param name="from">a point the line starts at</param>
        /// <param name="to">a point the line ends at</param>
        public void AddNewLine(Point from, Point to)
        {
            _surfaces.Add(new Line(new Point(from.Xval, from.Yval), new Point(to.Xval, to.Yval )));
        }

        /// <summary>
        /// adds a new line with coordinates between 0 and 100 completely randomly
        /// </summary>
        public void AddNewRandomLine()
        {
            Random gen = new Random();
            Point from = new Point(gen.Next(100), gen.Next(100));
            Point to = new Point(gen.Next(100), gen.Next(100));

            this.AddNewLine(from, to);
        }

        /// <summary>
        /// returns the map as an array of boolean values from 0 to 100, 0 to 100
        /// if the value is false, the terrain is impassable, if the value is true, the terrain is
        /// passable
        /// </summary>
        public bool[,] MapData
        {
            get
            {
                bool[,] toret = new bool[100,100];

                //initialize the array to true(default is false)
                for (int xind = 0; xind < 100; xind++ )
                {
                    for (int yind = 0; yind < 100; yind++)
                    {
                        toret[xind, yind] = true;
                    }
                }
                //negate out all the surface area as impassable
                //get the initial point, negate it, get the slope,s
                //negate every value along the slope until the end.
                foreach (Line negate in Surfaces)
                {
                    //calculate the difference in xvalues and the difference in y values
                    int xdif = negate.PointA.Xval - negate.PointB.Xval;
                    int ydif = negate.PointA.Yval - negate.PointB.Yval;
                    //number of decrements to make
                    int decs = 0;
                    Point init = negate.PointA;

                    //general algorithm:
                    //While not done, reduce the larger of x and y dif by an amount proportional
                    //to the difference between them, then reduce the lesser by 1. This creates a
                    //balancing act, so the larger is 9 and the lesser is 3, the larger will be reduced
                    //by 3, and the lesser will be reduced by 1, repeat.
                    //In the process "walk" along as many as the larger number is decremented by,
                    //negating them.
                    //Pass the new initial point into the loop.
                    while (xdif > 0 && ydif > 0)
                    {
                        //calculate which one to reduce by many
                        if (xdif > ydif)
                        {
                            //number of x decrements to do
                            decs = (int)Math.Ceiling((double)(xdif / ydif));
                            for (int i = 0; i <= decs; i++)
                            {
                                toret[init.Xval + (decs - i), init.Yval] = false;
                            }

                            init = new Point((init.Xval - decs), init.Yval - 1);
                        }
                        else
                        {
                            //number of y decrements to do
                            decs = (int)Math.Ceiling((double)(xdif / ydif));
                            for (int i = 0; i <= decs; i++)
                            {
                                toret[init.Xval, (init.Yval + (decs -i))] = false;
                            }

                            init = new Point((init.Xval - 1), init.Yval - decs);
                        }
                    }


                    toret[(int)negate.PointA.Xval, (int)negate.PointB.Yval] = false;

                    


                }
                return toret;
                     
            }
        }
    }
}
