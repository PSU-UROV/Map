#include "cube.h"

Cube::Cube()
	: m_size(0)
{
}

Cube::Cube(const Vector &center,
           const Vector &size)
	: m_center(center)
	, m_size(size)
{
}

