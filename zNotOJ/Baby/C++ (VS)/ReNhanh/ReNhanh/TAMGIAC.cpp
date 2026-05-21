#include <iostream>
#include <cmath>
#include <string>

using namespace std;

long double a;
long double b;
long double c;

string result;

bool isAllowed;

int main()
{
	cin >> a >> b >> c;

	isAllowed = true;

	if (a + b + c == 180 && a > 0 && b > 0 && c > 0)
	{
		result = "THUONG";

		if (a == b && b == c)
		{
			result = "DEU";
			isAllowed = false;
		}
		if (a == 90 || b == 90 || c == 90)
		{
			isAllowed = false;

			if (a == 45 || b == 45 || c == 45)
			{
				result = "VUONG CAN";
			}
			else
			{
				result = "VUONG";
			}
		}
		if (isAllowed == true)
		{
			if (a == b || b == c || c == a)
			{
				result = "CAN";
				isAllowed = false;
			}
		}
	}
	else
	{
		result = "0";
	}


	cout << result;
}