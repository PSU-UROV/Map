#ifndef OCT_NODE_H
#define OCT_NODE_H

#include "cube.h"
#include "vector.h"

class OctNode
	: public Cube
{

	public:
		OctNode();

		void insert(Surface *surface);

	private:
		Vector m_center;
		float m_size;

		// Octree nodes
		OctNode *ufl;
		OctNode *ufr;
		OctNode *ubl;
		OctNode *ubr;
		OctNode *dfl;
		OctNode *dfr;
		OctNode *dbl;
		OctNode *dbr;

};

#endif

