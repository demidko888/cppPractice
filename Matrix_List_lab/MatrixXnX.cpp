#include <random>
#include <cassert>
#include <ctime>
#include "MatrixXnX.h"

using namespace std;
MatrixXnX::MatrixXnX(const int iDim) : dim(iDim) {
    matrix = new int[dim * dim];
    for (int i = 0; i < dim; i++)
        for (int j = 0; j < dim; j++)
            matrix[getLinIndex(i, j)] = 0;
}

int MatrixXnX::element(const int i, const int j) const {
    assert(i >= 0 && i < dim && j >= 0 && j < dim);
    return  matrix[getLinIndex(i, j)];
}

void MatrixXnX::setElement(const int i, const int j, const int value) {
    assert(i >= 0 && i < dim && j >= 0 && j < dim);
    matrix[getLinIndex(i, j)] = value;
}

void MatrixXnX::fillRandomElements(const int minVal, const int maxVal) {
    default_random_engine randomizer(time(0));
    uniform_int_distribution<int> distribution(minVal, maxVal - 1);
    for (int i = 0; i < dim; i++)
        for (int j = 0; j < dim; j++)
            matrix[getLinIndex(i, j)] = distribution(randomizer);
}

int MatrixXnX::sumPrincipalDiag() const {
    int sum = 0;
    for (int i = 0; i < dim; i++)
        sum += matrix[getLinIndex(i, i)];
    return sum;
}

int MatrixXnX::sumSecondaryDiag() const {
    int sum = 0;
    for (int i = dim - 1; i >= 0; i--)
        sum += matrix[getLinIndex(i, dim - 1 - i)];
    return sum;
}

int MatrixXnX::productPrincipalDiag() const {
    int result = 1;
    for (int i = 0; i < dim; i++)
        result *= matrix[getLinIndex(i, i)];
    return result;
}

int MatrixXnX::productSecondaryDiag() const {
    int result = 1;
    for (int i = dim - 1; i >= 0; i--)
        result *= matrix[getLinIndex(i, dim - 1 - i)];
    return result;
}

int MatrixXnX::sumRow(const int iRow) const {
    assert(iRow >= 0 && iRow < dim);
    int sum = 0;
    for (int j = 0; j < dim; j++)
        sum += matrix[getLinIndex(iRow, j)];
    return sum;
}

int MatrixXnX::minColumn(const int iCol) const {
    assert(iCol >= 0 && iCol < dim);
    int min = matrix[getLinIndex(0, iCol)];
    for (int j = 1; j < dim; j++)
        if (min > matrix[getLinIndex(j, iCol)])
            min = matrix[getLinIndex(j, iCol)];
    return min;
}

int MatrixXnX::maxColumn(const int iCol) const {
    assert(iCol >= 0 && iCol < dim);
    int max = matrix[getLinIndex(0, iCol)];
    for (int j = 1; j < 3; j++)
        if (max < matrix[getLinIndex(j, iCol)])
            max = matrix[getLinIndex(j, iCol)];
    return max;
}

int MatrixXnX::getLinIndex(const int i, const int j) const {
    return i * dim + j;
}

int MatrixXnX::getDim() const {
    return dim;
}

MatrixXnX::~MatrixXnX() {
    delete[] matrix;
}
