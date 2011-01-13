#include "matrixops.h"

namespace MatrixOps
{

float determinant(const Matrix2x2f &matrix)
{
	float ad = matrix[0][0] * matrix[1][1];
	float bc = matrix[0][1] * matrix[1][0];
	return ad - bc;
}

}

