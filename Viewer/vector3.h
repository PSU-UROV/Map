#ifndef VECfloatOR3F_H
#define VECfloatOR3F_H

#include <vector>

class Vector3f
	: public std::vector<float>
{

	public:
		Vector3f();
		Vector3f(float x,
		         float y,
		         float z);

		const float &x() const;
		const float &y() const;
		const float &z() const;

};

#endif

