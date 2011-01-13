using System;
using System.Collections.Generic;
using System.Runtime.Serialization;
using System.Linq;
using System.Text;

namespace MapData
{
    /// <summary>
    /// Point is an immutable x/y value pair, initialized by the constructor
    /// This struct is designed to be interoperable simply(blittable)
    /// </summary>
    [DataContract]
    public struct Point
    {
           [DataMember]
           private readonly int _xval;
           [DataMember]
           private readonly int _yval;
           /// <summary>
           /// builds an immutable point
           /// </summary>
           /// <param name="xval">assigns the x value</param>
           /// <param name="yval">assigns the yvalue</param>
           public Point(int xval, int yval)
           {
               this._xval = xval;
               this._yval = yval;

           }


            /// <summary>
            /// returns the xValue
            /// </summary>
           public int Xval
           {
               get
               {
                   return _xval;
               }
           }

            /// <summary>
            /// returns the yvalue
            /// </summary>
           public int Yval
           {
               get
               {
                   return _yval;
               }
           }
    }

    /// <summary>
    /// a line is an immutable struct of 2 points, it has one function
    /// that tests if another line intersects this line
    /// </summary>
    [DataContract]
    public struct Line
    {
        [DataMember]
        private readonly Point _pointa;
        [DataMember]
        private readonly Point _pointb;

        /// <summary>
        /// builds an immutable line
        /// </summary>
        /// <param name="pointa">assigns point A immutably</param>
        /// <param name="pointb">assigns B immutably</param>
        public Line(Point pointa, Point pointb)
        {
            _pointa = pointa;
            _pointb = pointb;
        }
    

        /// <summary>
        /// returns point a
        /// </summary>
        public Point PointA
        {
            get
            {
                return _pointa;
            }
        }

        /// <summary>
        /// returns point b
        /// </summary>
        public Point PointB
        {
            get
            {
                return _pointb;
            }
        }

        /// <summary>
        /// Tests whether or not another line intersects with this one
        /// designed for testing paths composed of vectors
        /// </summary>
        /// <param name="test">the line to test against</param>
        /// <returns>true if it does intersect, false if it doesn't. Note this may be inverted logic to
        /// what is desired since most likely you are looking for "does not cross", i.e. "doesn cross == false"
        /// </returns>
        ///<remarks> code partially cribbed from http://local.wasp.uwa.edu.au/~pbourke/geometry/lineline2d/Helpers.cs
        ///http://local.wasp.uwa.edu.au/~pbourke/geometry/lineline2d/
        /// second one is the math
        ///</remarks>
        public bool DoesIntersect(Line test)
        {
            float denominator = (test.PointA.Yval - test.PointB.Yval) * (this.PointA.Xval - this.PointB.Xval)
                        - (test.PointA.Xval - test.PointA.Xval) * (this.PointA.Yval - this.PointB.Yval);


            float numerator_a = (test.PointA.Xval - test.PointB.Xval) * (this.PointB.Yval - test.PointB.Yval)
                            - (test.PointA.Yval - test.PointB.Yval) * (this.PointB.Xval - test.PointA.Xval);

            float numerator_b = (this.PointA.Xval - this.PointB.Xval) * (this.PointB.Yval - test.PointB.Yval)
                            - (this.PointA.Yval - this.PointB.Yval) * (this.PointB.Xval - test.PointA.Xval);


            //supposedly this solves if the two lines are parallell and touch(need to run the numbers myself)
            //I suspect there is a bug if 2 lines are paralell and overlapping for part(will test and eventually correct)
            //There may also be a bug with single points on the line
            if(denominator == 0)
                return false;

            double slopea = numerator_a / denominator;
            double slopeb = numerator_b / denominator;

            //if slopea is between 0 and 1, and slopeb is between 0 and one, then the two lines intersect
            if (slopea >= 0 && slopea <= 1 && slopeb >= 0 && slopeb <= 1)
            {
                return true;
            }
            else
            {
                return false;
            }

            
        }
    }
}
