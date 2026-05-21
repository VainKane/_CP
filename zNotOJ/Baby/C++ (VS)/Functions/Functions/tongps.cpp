#include <iostream>

int GCD(long long a, long long b);


long long a;
long long b;
long long c;
long long d;

int gcd;

int main()
{
	std::cin >> a >> b >> c >> d;

	gcd = GCD(a * d - b * c, b * d);

	
	if (static_cast<long long>(a * d - b * c) * (b * d) < 0)
	{
		std::cout << '-';
	}

	std::cout << abs((a * d - b * c) / gcd);
	std::cout << '/';
	std::cout << abs((b * d) / gcd);
}

int GCD(long long a, long long b)
{
	a = abs(a);
	b = abs(b);

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
