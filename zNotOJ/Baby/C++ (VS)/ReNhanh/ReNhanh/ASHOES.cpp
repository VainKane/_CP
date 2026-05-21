#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int red;
	int blue;

	int richDays;
	int poolDays;

	int min;

	cin >> red >> blue;

	if (red <= blue)
	{
		richDays = red;
		poolDays = (blue - richDays) / 2;
	}
	else if (blue < red)
	{
		richDays = blue;
		poolDays = (red - richDays) / 2;
	}

	cout << richDays << " " << poolDays;
}

