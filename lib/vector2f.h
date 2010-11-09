#ifndef VECTOR_2_F_H
#define VECTOR_2_F_H

#include <vector>

class Vector2f
	: std::vector<float>
{

	public:
		Vector2f();
		Vector2f(float x,
		        float y);

		float x() const;
		float y() const;

};

#endif

