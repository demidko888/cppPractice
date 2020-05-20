#include <iostream>
#include "BinaryTree.h"
#include "TreeNode.h"

using namespace std;

void Swap(int* first, int* second) {
    int tmp = *first;
    *first = *second;
    *second = tmp;
}

void BubbleSort(int* arr, int length) {
    int tmp;
    for (int i = 0; i < length - 1; i++)
        for (int j = 0; j < length - i - 1; j++)
            if (arr[j] > arr[j + 1]) 
                Swap(&arr[j], &arr[j + 1]);
}

TreeNode* CreateMinimalBST(const int* arr, const int start, const int end) {
    if (end < start)
        return nullptr;
    const int mid = (start + end) / 2;
    auto tree = new TreeNode(arr[mid]);
    tree->SetLeftNode(CreateMinimalBST(arr, start, mid - 1));
    tree->SetRightNode(CreateMinimalBST(arr, mid + 1, end));
    return tree;
}

int main() {
    BinaryTree tree;
    tree.Insert(5);
    tree.Insert(6);
    tree.Insert(10);
    tree.Insert(3);
    tree.Insert(4);
    tree.Insert(7);
    if (tree.Search(2))
        cout << tree.Search(2)->GetValue() << endl;
    int arr[] = { 9, 10, 0, 5, 6 };
    BubbleSort(arr, sizeof(arr) / sizeof(arr[0]));
    BinaryTree minimalTree;
    minimalTree.SetRoot(CreateMinimalBST(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1));
    return 0;
}



