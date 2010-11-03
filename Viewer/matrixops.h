#ifndef MATRIX_OPS_H
#define MATRIX_OPS_H

#include <vector>

#include "vector2.h"
#include "vector3.h"

namespace MatrixOps
{

float determinant(std::vector< std::vector<float> > matrix);

// Vectors are [rows][columns]
float determinant(vector2< vector2<float> > matrix);

}

#endif

