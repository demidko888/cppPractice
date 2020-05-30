#include <iostream>
#include "Matrix2D.h"
#include "Matrix3D.h"
#include "MatrixBase.h"

using namespace std;

void FillMatrix2D(Matrix2D& matrix, int size);
void FillMatrix3D(Matrix3D& matrix, int size);

int main()
{
    Matrix2D m2a, m2b;

    FillMatrix2D(m2a, m2a.size());
    FillMatrix2D(m2b, m2b.size());

    Matrix3D m3a, m3b;

    FillMatrix3D(m3a, m3a.size());
    FillMatrix3D(m3b, m3b.size());
    
    cout << "m2a:" << endl<< m2a<< endl;
    cout << "m2b:" << endl << m2b << endl;
    cout << "m3a:" << endl << m3a << endl;
    cout << "m3b:" << endl << m3b << endl;
    m2b *= 5;
    cout << "m2b*5:"<< endl << m2b << endl;
    m2a += m2b;
    cout << "m2a+m2b*5:" << endl << m2a << endl;
    cout << "m3a:" << endl << m3a << endl;
    m3a *= 10;
    cout << "m3a*10:" << endl << m3a << endl;
    m3a += m3b;
    cout << "m3a+m3b:" << endl << m3a << endl;
    return 0;
}

void FillMatrix2D(Matrix2D& matrix, int size) {
    int number = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            matrix.element(i, j) = ++number;
}

void FillMatrix3D(Matrix3D& matrix, int size) {
    int number = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            matrix.element(i, j) = ++number;
}

