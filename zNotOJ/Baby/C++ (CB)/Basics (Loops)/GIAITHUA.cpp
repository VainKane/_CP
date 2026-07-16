#include <iostream>

int n;
long long result;

int main()
{
	std::cin >> n;

	result = 1;

	for (int i = 2; i <= n; i++)
	{
		result *= i;
	}

	std::cout << result;
}
