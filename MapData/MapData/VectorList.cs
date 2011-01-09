using System;
using System.Runtime.Serialization;
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
    [DataContract]
    public class Map
    {
        //the different internal representations of a map
        [DataMember]
        private readonly List<Line> _surfaces = new List<Line>();
        [DataMember]
        private bool[,] _pixelmap = new bool[100, 100];

        /// <summary>
        /// empty constructor, preps the pixel map
        /// </summary>
        Map()
        {
            //initialize the array to true(default is false)
            for (int xind = 0; xind < 100; xind++)
            {
                for (int yind = 0; yind < 100; yind++)
                {
                    _pixelmap[xind, yind] = true;
                }
            }
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
            Line toadd = new Line(new Point(from.Xval, from.Yval), new Point(to.Xval, to.Yval));
            _surfaces.Add(toadd);
            ModifyArray(toadd);
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
                return _pixelmap;
            }
        }

        private void ModifyArray(Line tomod)
        {

            //negate out all the surface area as impassable
            //get the initial point, negate it, get the slope,s
            //negate every value along the slope until the end.

            //calculate the difference in xvalues and the difference in y values
            int xdif = tomod.PointA.Xval - tomod.PointB.Xval;
            int ydif = tomod.PointA.Yval - tomod.PointB.Yval;

            //number of decrements to make
            int decs = 0;
            Point init = tomod.PointA;

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
                    decs = (int)(Math.Abs(Math.Ceiling((double)(xdif / ydif))));
                    //walk the negations backwards
                    for (int i = 0; i <= decs; i++)
                    {
                        _pixelmap[init.Xval - ((decs - i) * Math.Sign(xdif)), init.Yval] = false;
                    }
                    //pass the next point to start from in
                    init = new Point((init.Xval - decs), init.Yval - (1 * (Math.Sign(ydif))));
                    //calculate the difference in xvalues and the difference in y values
                    //needed to break out of loop
                    xdif = xdif + decs;
                    ydif = ydif - (1 * Math.Sign(xdif));
                }
                else
                {
                    //number of y decrements to do
                    decs = (int)Math.Abs(Math.Ceiling((double)(xdif / ydif)));

                    for (int i = 0; i <= decs; i++)
                    {
                        _pixelmap[init.Xval, (init.Yval - ((decs - i) * Math.Sign(ydif)))] = false;
                    }

                    init = new Point((init.Xval - (1 * Math.Sign(xdif))), init.Yval - (decs * Math.Sign(ydif)));
                    //calculate the difference in xvalues and the difference in y values
                    //needed to break out of loop
                    xdif = xdif - (1 * Math.Sign(xdif));
                    ydif = ydif - (decs * Math.Sign(ydif));
                }
            }
        }
    }
}

