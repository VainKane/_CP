#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	int a;
	int b;
	int c;

	int min;
	int max;
	int mid;

	cin >> a >> b >> c;

	min = a;
	max = a;

	if (min > b)
	{
		min = b;
	}
	if (min > c)
	{
		min = c;
	}


	if (max < b)
	{
		max = b;
	}
	if (max < c)
	{
		max = c;
	}

	mid = a + b + c - min - max;

	cout << min << " " << mid << " " << max;
}