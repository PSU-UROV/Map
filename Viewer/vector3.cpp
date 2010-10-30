#include "vector3.h"

Vector3::Vector3()
	: std::vector<float>(3, 0)
{
}

Vector3::Vector3(float x,
               float y,
               float z)
	: std::vector<float>(3, 0)
{
	assign(0, x);
	assign(1, y);
	assign(2, z);
}

float Vector3::x() const
{
	return at(0);
}

float Vector3::y() const
{
	return at(1);
}

float Vector3::z() const
{
	return at(2);
}

float Vector3::dotProd(const Vector3 &other) const
{
	float ret = 0;
	ret += other.x() * x();
	ret += other.y() * y();
	ret += other.z() * z();
	return ret;
}


