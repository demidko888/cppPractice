#include <iostream>
#include <ctime>
#include <random>
#include <vector>
#include <cassert>
#include "Matrix3x3.h"
#include "MatrixXnX.h"
#include "Node.h"

using namespace std;

void WorkWithMatrix3x3();
void WorkWithMatrixXnX();
void PrintMatrix3x3(Matrix3x3 matrix);
void PrintMatrixXnX(MatrixXnX& matrix);
void WorkWithList();
void PrintList(Node& list);
void DistinctLinkedList(Node& root);
bool VectorContains(vector<int> vector, int value);
int FindKElementFromEnd(Node& list, int k);

int main()
{
    WorkWithMatrix3x3();
    WorkWithMatrixXnX();
    WorkWithList();
}

#pragma region Functions

void PrintMatrix3x3(Matrix3x3 matrix) {
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << matrix.element(i, j) << "\t";
        cout << endl;
    }
}

void WorkWithMatrix3x3() {
    Matrix3x3 matrix3x3 = Matrix3x3();
    matrix3x3.fillRandomElements(-10, 10);
    PrintMatrix3x3(matrix3x3);
    cout << "productPrincipalDiag = " << matrix3x3.productPrincipalDiag() << endl;
    cout << "productSecondaryDiag = " << matrix3x3.productSecondaryDiag() << endl;
    cout << "sumPrincipalDiag = " << matrix3x3.sumPrincipalDiag() << endl;
    cout << "sumSecondaryDiag = " << matrix3x3.sumSecondaryDiag() << endl;
    for (int i = 0; i < 3; ++i)
        cout << "sum of " << i + 1 << " Row = " << matrix3x3.sumRow(i) << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "Column " << i + 1 << ":" << endl;
        cout << "min = " << matrix3x3.minColumn(i) << endl;
        cout << "max = " << matrix3x3.maxColumn(i) << endl;
    }
    cout << "-------------------------------------\n";
}

void WorkWithMatrixXnX() {
    int iDim = 4;
    MatrixXnX matrixXnX(iDim);
    matrixXnX.fillRandomElements(-10, 10);
    PrintMatrixXnX(matrixXnX);
    cout << "productPrincipalDiag = " << matrixXnX.productPrincipalDiag() << endl;
    cout << "productSecondaryDiag = " << matrixXnX.productSecondaryDiag() << endl;
    cout << "sumPrincipalDiag = " << matrixXnX.sumPrincipalDiag() << endl;
    cout << "sumSecondaryDiag = " << matrixXnX.sumSecondaryDiag() << endl;
    for (int i = 0; i < iDim; ++i)
        cout << "sum of " << i + 1 << " Row = " << matrixXnX.sumRow(i) << endl;
    for (int i = 0; i < iDim; ++i) {
        cout << "Column " << i + 1 << ":" << endl;
        cout << "min = " << matrixXnX.minColumn(i) << endl;
        cout << "max = " << matrixXnX.maxColumn(i) << endl;
    }
    cout << "-------------------------------------\n";
}

void PrintMatrixXnX(MatrixXnX& matrix) {
    int dim = matrix.getDim();
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++)
            cout << matrix.element(i, j) << "\t";
        cout << endl;
    }
}

void WorkWithList() {
    Node linkedList = Node(0);
    for (int i = 1; i < 10; i++) {
        linkedList.push(new Node(i));
        linkedList.push(new Node(23));
    }
    PrintList(linkedList);
    DistinctLinkedList(linkedList);
    PrintList(linkedList);
    //если считаем с 1
    cout << "3 element from end = " << FindKElementFromEnd(linkedList, 3) << endl;
}

void PrintList(Node& list) {
    Node* head = &list;
    while (head != nullptr) {
        cout << head->getValue() << " ";
        head = head->getNext();
    }
    cout << endl;
}

void DistinctLinkedList(Node& root) {
    vector<int> a;
    Node* ptr = &root;
    a.push_back(ptr->getValue());
    while (ptr->getNext()) {
        if (VectorContains(a, ptr->getNext()->getValue())) {
            ptr->deleteNext();
            continue;
        }
        a.push_back(ptr->getNext()->getValue());
        ptr = ptr->getNext();
    }
}

bool VectorContains(vector<int> vector, int value) {
    for (int i = 0; i < vector.size(); i++)
        if (vector[i] == value)
            return true;
    return false;
}

int FindKElementFromEnd(Node& list, int k) {
    int count = 0;
    Node* ptr = &list;
    while (ptr != nullptr) {
        count++;
        ptr = ptr->getNext();
    }
    assert(k < count);
    ptr = &list;
    for (int i = 0; i < count - k; i++) 
        ptr = ptr->getNext();
    return ptr->getValue();
}
#pragma endregion





