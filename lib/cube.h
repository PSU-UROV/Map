#ifndef CUBE_H
#define CUBE_H

#include "plane.h"

class Cube
{

	public:
		Cube();

		/** A cube is defined by a plane and size
		    Size can be thought of as 1/2 * width */
		Cube(const Plane &plane,
		     float size);

		const Plane &plane() const;
		float size() const;

		bool isAxisAligned(const Cube &other) const;

	private:
		Plane m_plane;
		float m_size;

};

#endif

