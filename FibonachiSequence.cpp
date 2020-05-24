#include <iostream>

using namespace std;
int main()
{
	int n;
	cin >> n;
	int previous = 0;
	int current = 1;
	for(int i=0;i<n;i++)
	{
		cout << previous << endl;
		current = previous + current;
		previous = current-previous;
	}
	return 0;

}


