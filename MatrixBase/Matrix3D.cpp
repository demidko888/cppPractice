#include "Matrix3D.h"

Matrix3D::Matrix3D():MatrixBase(DIM){
	int number = 0;
	for (int i = 0; i < DIM; i++)
		for (int j = 0; j < DIM; j++)
			matrix[i][j] = ++number;
}

int Matrix3D::element(unsigned int i, unsigned int j) const{
	return matrix[i][j];
}

int& Matrix3D::element(unsigned int i, unsigned int j){
	return matrix[i][j];
}
