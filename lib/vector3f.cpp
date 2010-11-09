#include "vector3f.h"

#include "matrixops.h"
#include "matrix2x2f.h"

Vector3f::Vector3f()
	: std::vector<float>(3, 0)
{
}

Vector3f::Vector3f(float x,
                   float y,
                   float z)
	: std::vector<float>(3, 0)
{
	assign(0, x);
	assign(1, y);
	assign(2, z);
}

float Vector3f::x() const
{
	return at(0);
}

float Vector3f::y() const
{
	return at(1);
}

float Vector3f::z() const
{
	return at(2);
}


float Vector3f::dotProd(const Vector3f &other) const
{
	float ret = 0;
	ret += other.x() * x();
	ret += other.y() * y();
	ret += other.z() * z();
	return ret;
}

Vector3f *Vector3f::calcNormal(const Vector3f &other) const
{
	// Determinant of these matricies will be i, j, k 
	// vectors of the normal
	Matrix2x2f deti, detj, detk;

	deti[0][0] = y();
	deti[0][1] = z();
	deti[1][0] = other.y();
	deti[1][1] = other.z();

	detj[0][0] = x();
	detj[0][1] = z();
	detj[1][0] = other.x();
	detj[1][1] = other.z();

	detk[0][0] = x();
	detk[0][1] = y();
	detk[1][0] = other.x();
	detk[1][1] = other.y();

	Vector3f *normal = new Vector3f();
	(*normal)[0] = MatrixOps::determinant(deti);
	(*normal)[1] = MatrixOps::determinant(detj);
	(*normal)[2] = MatrixOps::determinant(detk);

	return normal;
}

