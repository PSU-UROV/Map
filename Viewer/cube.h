#ifndef CUBE_H
#define CUBE_H

#include "volume.h"
#include "vector.h"

class Cube
	: public Volume
{

	public:
		Cube();

		/** Two sides are nomal to the size vector
		    and the rest are parallel.  The size
		    vector is 1/2 the length of a side  **/
		Cube(const Vector &center,
		     const Vector &size);

	private:
		Vector m_center
		Vector m_size;

};

#endif

