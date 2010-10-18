#ifndef VECTOR3_H
#define VECTOR3_H

class Vector3
{

	public:
		Vector3();
		Vector3(float x,
		       float y,
		       float z);
		Vector3(const Vector3 &other);

		Vector3 &operator = (const Vector3 &other);

		float x() const;
		float y() const;
		float z() const;

		float dotProd(const Vector3 &other) const;

	private:
		float m_x;
		float m_y;
		float m_z;

};

#endif

