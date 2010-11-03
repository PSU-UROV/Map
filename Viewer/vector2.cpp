#include "vector2.h"

template <class T>
Vector2::Vector2()
	: std::vector<T>(2, 0)
{
}

template <class T>
Vector2::Vector2(T x,
                 T y)
	: std::vector<T>(2, 0)
{
	assign(0, x);
	assign(1, y);
}

T Vector2::x() const
{
	return at(0);
}

T Vector2::y() const
{
	return at(1);
}

