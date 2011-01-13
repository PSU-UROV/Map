#include "surface.h"

Surface::Surface()
{
}

Surface::Surface(Vector location,
                 Vector v1,
                 Vector v2)
{
	m_location = location;
	m_v1 = v1;
	m_v2 = v2;
}

