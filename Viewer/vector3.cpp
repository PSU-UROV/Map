#include "vector3f.h"

#include "vector2f.h"

Vector3f::Vector3f()
	: std::vector<float>(3, 0)
{
}

Vector3f::Vector3f(const float &x,
                 const float &y,
                 const float &z)
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

Vector3f *Vector3f::calcNormal() const
{
	// Determinant of these matricies will be i, j, k 
	// vectors of the normal
	vector2f< vector2f<float> > deti;
	vector2f< vector2f<float> > detj;
	vector2f< vector2f<float> > detk;

	deti[0][0] = m_vect1[1];
	deti[0][1] = m_vect1[2];
	deti[1][0] = m_vect2[1];
	deti[1][1] = m_vect2[2];

	detj[0][0] = m_vect1[0];
	detj[0][1] = m_vect1[2];
	detj[1][0] = m_vect2[0];
	detj[1][1] = m_vect2[2];

	detk[0][0] = m_vect1[0];
	detk[0][1] = m_vect1[1];
	detk[1][0] = m_vect2[0];
	detk[1][1] = m_vect2[1];

	Vector3f<float> *normal = new Vector3f<float>();
	normal[0] = matrixops::determinant(deti);
	normal[1] = matrixops::determinant(detj);
	normal[2] = matrixops::determinant(detk);

	return normal;
}

