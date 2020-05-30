#include <iostream>
#include "Matrix2D.h"
#include "Matrix3D.h"
#include "MatrixBase.h"

using namespace std;

int main()
{
    //объявили по два экземпляра матриц 2х2 и 3х3
    Matrix2D m2a, m2b;
    Matrix3D m3a, m3b;
    
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

