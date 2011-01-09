using System;
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
                //negate out all the surface area as impassable
                //get the initial point, negate it, get the slope,
                //negate every value along the slope until the end.
                foreach (Line negate in Surfaces)
                {
                    float slope = (negate.PointA.Yval - negate.PointB.Yval) / (negate.PointA.Xval - negate.PointB.Xval);

                    toret[(int)negate.PointA.Xval, (int)negate.PointB.Yval] = false;

                }
                return toret;
                     
            }
        }
    }
}
