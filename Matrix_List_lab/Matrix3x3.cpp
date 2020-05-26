#include <cassert>
#include <random>
#include <ctime>
#include "Matrix3x3.h"

using namespace std;

Matrix3x3::Matrix3x3() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            matrix[i][j] = 0;
}

void Matrix3x3::setElement(const int i, const int j, const int value) {
    assert(i >= 0 && i <= 2 && j >= 0 && j <= 2);
    matrix[i][j] = value;
}

int Matrix3x3::element(const int i, const int j) const {
    assert(i >= 0 && i <= 2 && j >= 0 && j <= 2);
    return matrix[i][j];
}

void Matrix3x3::fillRandomElements(const int minVal, const int maxVal) {
    default_random_engine randomizer(time(0));
    uniform_int_distribution<int> distribution(minVal, maxVal - 1);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            matrix[i][j] = distribution(randomizer);
}

int Matrix3x3::sumPrincipalDiag() const {
    int sum = 0;
    for (int i = 0; i < 3; i++)
        sum += matrix[i][i];
    return sum;
}

int Matrix3x3::sumSecondaryDiag() const {
    int sum = 0;
    for (int i = 2; i >= 0; i--)
        sum += matrix[i][2 - i];
    return sum;
}

int Matrix3x3::productPrincipalDiag() const {
    int result = 1;
    for (int i = 0; i < 3; i++)
        result *= matrix[i][i];
    return result;
}

int Matrix3x3::productSecondaryDiag() const {
    int result = 1;
    for (int i = 2; i >= 0; i--)
        result *= matrix[i][2 - i];
    return result;
}

int Matrix3x3::sumRow(const int iRow) const {
    assert(iRow >= 0 && iRow < 3);
    int sum = 0;
    for (int j = 0; j < 3; j++)
        sum += matrix[iRow][j];
    return sum;
}

int Matrix3x3::minColumn(const int iCol) const {
    assert(iCol >= 0 && iCol < 3);
    int min = matrix[0][iCol];
    for (int i = 1; i < 3; i++)
        if (min > matrix[i][iCol])
            min = matrix[i][iCol];
    return min;
}

int Matrix3x3::maxColumn(const int iCol) const {
    assert(iCol >= 0 && iCol < 3);
    int max = matrix[0][iCol];
    for (int i = 1; i < 3; i++)
        if (max < matrix[i][iCol])
            max = matrix[i][iCol];
    return max;
}
    


