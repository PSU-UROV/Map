#ifndef PLANE_H
#define PLANE_H

#include "vector3.h"

class Plane
{

	public:
		Plane();
		Plane(const Vector3 &vect1,
		      const Vector3 &vect2);
		Plane(const Plane &other);

		Plane &operator = (const Plane &other);

		const Vector3 &vect1() const;
		const Vector3 &vect2() const;

		bool isNormalTo(const Vector3 &other) const;

	private:
		const Vector3 m_vect1;
		const Vector3 m_vect2;

};

#endif

