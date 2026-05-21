#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int n;

	cin >> n;

	if (n % 2 != 0)
	{
		cout << n - (n - 1) / 2 + 1 << endl;
		cout << pow(n, 2) - n;
	}
	else
	{
		cout << n - (n - 1) / 2 << endl;
		cout << pow(n, 2) - n;
	}

}