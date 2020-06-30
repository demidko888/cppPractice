#include <cassert>
#include <random>
#include <ctime>
#include "Matrix3x3.h"

using namespace std;

Matrix3x3::Matrix3x3() {
    for (int i = 0; i < DIM; i++)
        for (int j = 0; j < DIM; j++)
            matrix[i][j] = 0;
}

void Matrix3x3::setElement(const int i, const int j, const int value) {
    assert(i >= 0 && i < DIM && j >= 0 && j < DIM);
    matrix[i][j] = value;
}

int Matrix3x3::element(const int i, const int j) const {
    assert(i >= 0 && i < DIM && j >= 0 && j < DIM);
    return matrix[i][j];
}

void Matrix3x3::fillRandomElements(const int minVal, const int maxVal) {
    default_random_engine randomizer(time(0));
    uniform_int_distribution<int> distribution(minVal, maxVal - 1);
    for (int i = 0; i < DIM; i++)
        for (int j = 0; j < DIM; j++)
            matrix[i][j] = distribution(randomizer);
}

int Matrix3x3::sumPrincipalDiag() const {
    int sum = 0;
    for (int i = 0; i < DIM; i++)
        sum += matrix[i][i];
    return sum;
}

int Matrix3x3::sumSecondaryDiag() const {
    int sum = 0;
    for (int i = DIM-1; i >= 0; i--)
        sum += matrix[i][DIM - 1 - i];
    return sum;
}

int Matrix3x3::productPrincipalDiag() const {
    int result = 1;
    for (int i = 0; i < DIM; i++)
        result *= matrix[i][i];
    return result;
}

int Matrix3x3::productSecondaryDiag() const {
    int result = 1;
    for (int i = DIM-1; i >= 0; i--)
        result *= matrix[i][DIM - 1 - i];
    return result;
}

int Matrix3x3::sumRow(const int iRow) const {
    assert(iRow >= 0 && iRow < DIM);
    int sum = 0;
    for (int j = 0; j < DIM; j++)
        sum += matrix[iRow][j];
    return sum;
}

int Matrix3x3::minColumn(const int iCol) const {
    assert(iCol >= 0 && iCol < DIM);
    int min = matrix[0][iCol];
    for (int i = 1; i < DIM; i++)
        if (min > matrix[i][iCol])
            min = matrix[i][iCol];
    return min;
}

int Matrix3x3::maxColumn(const int iCol) const {
    assert(iCol >= 0 && iCol < DIM);
    int max = matrix[0][iCol];
    for (int i = 1; i < DIM; i++)
        if (max < matrix[i][iCol])
            max = matrix[i][iCol];
    return max;
}
    


