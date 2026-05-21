#include <iostream>
#include <cmath>
#include <string>

using namespace std;

string TriangleCheck(int a, int b, int c);

int main()
{
	int a;
	int b;
	int c;

	string result;

	cin >> a >> b >> c;

	if (TriangleCheck(a, b, c) == "YES")
	{
		if ((a == b ) || (b == c) || (c == a))
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

string TriangleCheck(int a, int b, int c)
{
	string result;

	if (abs(b - c) < a && a < b + c)
	{
		result = "YES";
	}
	else
	{
		result = "NO";
	}

	return result;
}
