#include "Matrix3D.h"

int Matrix3D::element(unsigned int i, unsigned int j) const{
	return matrix[i][j];
}

int& Matrix3D::element(unsigned int i, unsigned int j){
	return matrix[i][j];
}
