#pragma once
#include "MatrixBase.h"

class Matrix2D : public MatrixBase {
public:

    int element(unsigned int i, unsigned int j) const override;

    int& element(unsigned int i, unsigned int j) override;

private:
    static constexpr int DIM = 2;

    int matrix[2][2];
};