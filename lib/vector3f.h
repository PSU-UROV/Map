#ifndef VECTOR3F_H
#define VECTOR3F_H

#include <vector>

class Vector3f
	: public std::vector<float>
{

	public:
		Vector3f();
		Vector3f(float x,
		         float y,
		         float z);

		float x() const;
		float y() const;
		float z() const;

		float dotProd(const Vector3f &other) const;
		Vector3f *calcNormal(const Vector3f &other) const;

};

#endif

