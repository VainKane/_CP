#include <bits/stdc++.h>

int GCD(int a, int b);
int GCD2(int a, int b);

long long a;
long long b;

int main()
{
	std::cin >> a >> b;

	std::cout << a / GCD2(a, b) << '/' << b / GCD2(a, b);

}

int GCD2(int a, int b)
{
	int r = a % b;

	if (r == 0)
	{
		return b;
	}
	else
	{
		while (r != 0)
		{
			r = a % b;
			a = b;
			b = r;
		}
		return a;
	}
}

int GCD(int a, int b)
{
	if (a * b == 0)
	{
		return a + b;
	}
	else
	{
	while (a != b)
	{
		if (a > b)
		{
			a -= b;
		}
		else
		{
			b -= a;
		}
	}
	return a;
	}
}