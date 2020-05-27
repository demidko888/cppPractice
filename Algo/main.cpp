#include <iostream>
#include <string>

using namespace std;

int findPrevMax(int* start, int* end);
void printArray(int* arr, int elementsCount);
void findMissingElement(int* start, int* end);

constexpr int SIZE = 10;

int main(){
   
	int arr[SIZE]{0,1,5,6,10,-5,34,222,0,12};
	cout << "Printed array : ";
	printArray(&arr[0], SIZE);
	cout << "Find previous maximum : " << findPrevMax(&arr[0], &arr[SIZE]) << endl;
	int sortedArr[10]{ 0,1,2,4,5,6,7,8,9,13};
	cout << "Printed array : ";
	printArray(&sortedArr[0], SIZE);
	findMissingElement(&sortedArr[0], &sortedArr[SIZE]);
	return 0;
}

void printArray(int* arr, int elementsCount) {
	for (int i = 0; i < elementsCount; i++) {
		cout << *(arr+i) << " ";
	}
	cout << endl;
}

int findPrevMax(int* start, int* end) {
	int max = INT_MIN;
	int prevMax = max;
	for (int i = 0; i <= end - start; i++) {
		if (*(start + i) > max) {
			if (max > prevMax) prevMax = max;
			max = *(start + i);
		}
	}
	return prevMax;
}

void findMissingElement(int* start, int* end) {
	for (int i = 1; i <= end - start; i++) {
		if (*(start + i) - *(start + i - 1) != 1) {
			int tmp = *(start+i-1)+1;
			while (tmp < *(start + i)) {
				cout << "Element " << tmp << " is missing!" << endl;
				tmp++;
			}
		}
	}
}
