#include <iostream>

int GCD(int a, int b);

long long a;
long long b;

int main()
{
	std::cin >> a >> b;

	std::cout << a / GCD(a, b) << '/' << b / GCD(a, b);
}

int GCD(int a, int b)
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