#ifndef PLANE_H
#define PLANE_H

#include "vector3f.h"

class Plane
{

	public:
		Plane();
		Plane(const Vector3f &vect1,
		      const Vector3f &vect2);
		Plane(const Plane &other);
		~Plane();

		Plane &operator = (const Plane &other);

		const Vector3f &vect1() const;
		const Vector3f &vect2() const;

		bool isNormalTo(const Vector3f &other) const;
		Vector3f *normal() const;

	private:

		Vector3f m_vect1;
		Vector3f m_vect2;

};

#endif

