#include "plane.h"

#include "vector3f.h"
#include "matrixops.h"

Plane::Plane()
{
}

Plane::Plane(const Vector3f &vect1,
             const Vector3f &vect2)
	: m_vect1(vect1)
	, m_vect2(vect2)
{
}

Plane::Plane(const Plane &other)
	: m_vect1(other.vect1())
	, m_vect2(other.vect2())
{
}

Plane::~Plane()
{
}

Plane &Plane::operator = (const Plane &other)
{
	m_vect1 = other.vect1();
	m_vect2 = other.vect2();
}

const Vector3f &Plane::vect1() const
{
	return m_vect1;
}

const Vector3f &Plane::vect2() const
{
	return m_vect2;
}

bool Plane::isNormalTo(const Vector3f &other) const
{
	return (!other.dotProd(m_vect1) && !other.dotProd(m_vect2));
}

Vector3f *Plane::normal() const
{
	return m_vect1.calcNormal(m_vect2);
}

