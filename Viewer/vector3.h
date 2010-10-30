#ifndef VECTOR3_H
#define VECTOR3_H

#include <vector>

class Vector3
	: public std::vector<float>
{

	public:
		Vector3();
		Vector3(float x,
		       float y,
		       float z);

		float x() const;
		float y() const;
		float z() const;

		float dotProd(const Vector3 &other) const;

};

#endif

