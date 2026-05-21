#include <iostream>
#include <cmath>
#include <string>

using namespace std;

long double a;
long double b;
long double c;

int main()
{
	string result;

	cin >> a >> b >> c;

	if (a > 0 && b > 0 && c > 0)
	{
		if (a == b && b == c && c == a)
		{
			result = "YES";
		}
		else
		{
			result = "NO";
		}
	}
	
	else
	{
		result = "NO";
	}

	cout << result;
}
