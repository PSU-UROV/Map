#ifndef SURFACE_H
#define SURFACE_H

class Surface
{

	public:
		Surface();

		/** Define a surface using a point and two orthogonal
		    vectors that frame the surface. **/
		Surface(Vector location,
		        Vector v1,
		        Vector v2);

	private:
		Vector m_location;
		Vector m_v1;
		Vector m_v2;

};

#endif

