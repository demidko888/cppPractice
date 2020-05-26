#include <iostream>
#include <cassert>

using namespace std;
void BinCalculator();
void FibonachiSequence();

int main()
{
	cout << "FibonachiSequence: " << endl;
	FibonachiSequence();
	cout << "-------------------------------" << endl;
	cout << "BinCalculator:" << endl;
	BinCalculator();
	return 0;
}

void BinCalculator() {
	int firstNumber;
	char operation;
	int secondNumber;
	cin >> firstNumber >> operation >> secondNumber;
	cout << "result = ";
	switch (operation)
	{
	case'+':
		cout << firstNumber + secondNumber;
		break;
	case'-':
		cout << firstNumber - secondNumber;
		break;
	case'*':
		cout << firstNumber * secondNumber;
		break;
	case'/':
	case':':
		assert(secondNumber != 0);
		cout << firstNumber / (double)secondNumber;
		break;
	default:
		break;
	}
}

void FibonachiSequence() {
	int res = 0;
	int tmp = 1;
	int n;
	cout << "Enter count of numbers : ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << res << " ";
		res = tmp + res;
		tmp = res - tmp;
	}
	cout << endl;
}

