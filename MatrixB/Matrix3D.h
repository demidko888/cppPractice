#pragma once
#include "MatrixBase.h"

class Matrix3D : public MatrixBase {
public:

    Matrix3D() :MatrixBase(DIM) {}

    int element(unsigned int i, unsigned int j) const override;

    int& element(unsigned int i, unsigned int j) override;

private:
    static constexpr int DIM = 3;
    int matrix[DIM][DIM];
};