#include <iostream>
#include <cmath>
#include <string>

using namespace std;

string TriangleCheck(int a, int b, int c);
string RightTriangleCheck(int a, int b, int c);
string IsoscelesTriangleCheck(int a, int b, int c);
string EquilateralTriangleCheck(int a, int b, int c);

int main()
{
	int a;
	int b;
	int c;

	string result;

	cin >> a >> b >> c;

	if (TriangleCheck(a, b, c) == "YES")
	{
		if (RightTriangleCheck(a, b, c) == "YES")
		{
			result = "vuong";
		}
		else if (EquilateralTriangleCheck(a, b, c) == "YES")
		{
			result = "deu";
		}
		else if (IsoscelesTriangleCheck(a, b, c) == "YES")
		{
			result = "can";
		}
		else
		{
			result = "thuong";
		}
	}
	else
	{
		result = "khong";
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

string RightTriangleCheck(int a, int b, int c)
{
	string result;

	if (TriangleCheck(a, b, c) == "YES")
	{
		if ((a * a + b * b == c * c) || (b * b + c * c == a * a) || (a * a + c * c == b * b))
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

	return result;
}


string IsoscelesTriangleCheck(int a, int b, int c)
{
	string result;

	if (TriangleCheck(a, b, c) == "YES")
	{
		if ((a == b) || (b == c) || (c == a))
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

	return result;
}

string EquilateralTriangleCheck(int a, int b, int c)
{
	string result;

	if (a == b && b == c)
	{
		result = "YES";
	}
	else
	{
		result = "NO";
	}

	return result;
}
