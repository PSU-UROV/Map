#include "cube.h"

Cube::Cube()
	: m_size(0)
{
}

Cube::Cube(const Plane &plane,
           float size)
	: m_plane(plane)
	, m_size(size)
{
}

const Plane &plane() const
{
	return m_plane;
}

float size() const
{
	return m_size;
}

bool Cube::isAxisAligned(const Cube &other) const
{
}

