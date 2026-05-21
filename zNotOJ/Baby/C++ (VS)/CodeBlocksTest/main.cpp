#include <iostream>
#include <cmath>

int n;
long long sum;

int main()
{
	std::cin >> n;

	sum = 0;

	for (int i = 1; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			sum += i + (n / i);
		}
	}

	if (n < sum)
	{
		std::cout << 1;
	}
	else
	{
		std::cout << 0;
	}
}
