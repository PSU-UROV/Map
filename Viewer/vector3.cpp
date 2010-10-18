#include "vector3.h"

Vector3::Vector3()
	: m_x(0)
	, m_y(0)
	, m_z(0)
{
}

Vector3::Vector3(float x,
               float y,
               float z)
	: m_x(x)
	, m_y(y)
	, m_z(z)
{
}

Vector3::Vector3(const Vector3 &other)
	: m_x(other.x())
	, m_y(other.y())
	, m_z(other.z())
{
}

Vector3 &Vector3::operator = (const Vector3 &other)
{
	m_x = other.x();
	m_y = other.y();
	m_z = other.z();
}

float Vector3::x() const
{
	return m_x;
}

float Vector3::y() const
{
	return m_y;
}

float Vector3::z() const
{
	return m_z;
}

float Vector3::dotProd(const Vector3 &other) const
{
	float ret = 0;
	ret += other.x() * x();
	ret += other.y() * y();
	ret += other.z() * z();
	return ret;
}


