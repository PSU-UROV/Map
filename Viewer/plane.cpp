#include "plane.h"

Plane::Plane()
{
}

Plane::Plane(const Vector3 &vect1,
             const Vector3 &vect2)
	: m_vect1(vect1),
	, m_vect2(vect2)
{
}

Plane::Plane(const Plane &other)
	: m_vect1(other.vect1())
	, m_vect2(other.vect2())
{
}

Plane &Plane::operator = (const Plane &other)
{
	m_vect1 = other.vect1();
	m_vect2 = other.vect2();
}

const Vector3 &Plane::vect1() const
{
	return m_vect1;
}

const Vector3 &Plane::vect2() const
{
	return m_vect2;
}

bool Plane::isNormalTo(const Vector3 &other) const
{
	return (!other.dotProd(m_vect1) && !other.dotProd(m_vect2))
}

