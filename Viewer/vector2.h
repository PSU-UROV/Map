#ifndef VECTOR_2_H
#define VECTOR_2_H

#include <vector>

template <class T>
class Vector2
	: std::vector<T>
{

	public:
		Vector2();
		Vector2(T x,
		        T y);

		T x() const;
		T y() const;

};

#endif

