#include <iostream>

int Sum(int n);

int n;
int result;

int main()
{
	std::cin >> n;

	result = Sum(n);

	while ((result) / 10 > 0)
	{
		result = Sum(result);
	}

	std::cout << result;
}

int Sum(int n)
{
	int sum = 0;

	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
	}

	if ((n / 10) < 0)
	{
		sum = n;
	}
	return sum;
}
