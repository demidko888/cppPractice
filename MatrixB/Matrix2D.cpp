#include "Matrix2D.h"

Matrix2D::Matrix2D():MatrixBase(DIM){
	int number = 0;
	for (int i = 0; i < DIM; i++)
		for (int j = 0; j < DIM; j++)
			matrix[i][j] = ++number;
}

int Matrix2D::element(unsigned int i, unsigned int j) const{
	return matrix[i][j];
}

int& Matrix2D::element(unsigned int i, unsigned int j){
	return matrix[i][j];
}
