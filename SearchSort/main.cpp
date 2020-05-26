#include <iostream>
#include <cassert>

using namespace std;

static constexpr int SIZE = 10;
void printArray(int* arr, int* SIZE);
int findMax(int* start, int* end);
void bubbleSort(int arr[]);

int main()
{
    int arr[SIZE] = { 5, 32, 54 ,90 ,0, 1 ,34 ,87, 65, 187 };
    cout << "Array : ";
    printArray(&arr[0], &arr[SIZE]);

    int start, end;
    cout << "Enter start and end of search : ";
    cin >> start >> end;
    assert(start <= SIZE && start >= 0 && end <= SIZE && end >= 0 && start < end);
    cout << "Max element = " << findMax(&arr[start], &arr[end]) << endl;
      
    bubbleSort(arr);
    cout << "Sorted array : ";
    printArray(&arr[0], &arr[SIZE]);
    return 0;
}

void printArray(int* start,int* end) {
    while (*start != *end) {
        cout << *start << " ";
        start++;
    }
    cout << endl;
}
int findMax(int* start, int* end) {
    int max = INT_MIN;
    while (start != end) {
        if (*start > max)
            max = *start;
        start++;
    }
    return max;
}

void bubbleSort(int arr[])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
    }
}
