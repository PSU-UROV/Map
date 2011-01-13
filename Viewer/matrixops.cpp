#include "matrixops.h"

namespace MatrixOps
{

float determinant(std::vector< std::vector<float> > matrix)
{
}

float determinant(vector2< vector2<float> > matrix)
{
	float ad = matrix[0][0] * matrix[1][1];
	float bc = matrix[0][1] * matrix[1][0];
	return ad - bc;
}

}

