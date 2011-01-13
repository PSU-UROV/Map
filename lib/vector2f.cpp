#include "vector2f.h"

Vector2f::Vector2f()
	: std::vector<float>(2, 0)
{
}

Vector2f::Vector2f(float x,
                 float y)
	: std::vector<float>(2, 0)
{
	assign(0, x);
	assign(1, y);
}

float Vector2f::x() const
{
	return at(0);
}

float Vector2f::y() const
{
	return at(1);
}

