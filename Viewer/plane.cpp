#include "plane.h"

#include "vector2f.h"
#include "matrixops.h"

Plane::Plane()
	: m_normal(0)
{
}

Plane::Plane(const Vector3f &vect1,
             const Vector3f &vect2)
	: m_vect1(vect1),
	, m_vect2(vect2)
	, m_normal(0)
{
}

Plane::Plane(const Plane &other)
	: m_vect1(other.vect1())
	, m_vect2(other.vect2())
	, m_normal(0)
{
}

Plane::~Plane()
{
	if(m_normal)
		delete m_normal;
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
	return (!other.dotProd(m_vect1) && !other.dotProd(m_vect2))
}

const Vector3f &Plane::normal() const
{
	if(!m_normal)
		calcNormal();
		
	return *m_normal;
}

void Vector3f &Plane::calcNormal()
{
	if(m_normal)
		delete m_normal;

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

	m_normal = new Vector3f<float>();
	m_normal[0] = matrixops::determinant(deti);
	m_normal[1] = matrixops::determinant(detj);
	m_normal[2] = matrixops::determinant(detk);
}

