#include "Matrix3D.h"

Matrix3D::Matrix3D() :MatrixBase(DIM) {
		for (int i = 0; i < DIM; i++)
			for (int j = 0; j < DIM; j++)
				matrix.element(i, j) = i*DIM+j;
	}

int Matrix3D::element(unsigned int i, unsigned int j) const{
	return matrix[i][j];
}

int& Matrix3D::element(unsigned int i, unsigned int j){
	return matrix[i][j];
}
