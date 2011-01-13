#ifndef SHAPE_H
#define SHAPE_H

class Shape
{

	public:
		enum {
			Cube,
		} Type;

		static bool isIntersecting(const Cube &cube1,
			const Cube &cube2);

		Shape();

		virtual ~Shape();

		virtual int type() const = 0;

};

#endif

