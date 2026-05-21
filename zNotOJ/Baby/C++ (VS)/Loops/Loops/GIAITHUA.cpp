#include <iostream>

int n;
int result;

int main()
{
	std::cin >> n;

	result = 1;

	for (int i = 1; i <= n; i++)
	{
		result *= i;
	}

	std::cout << result;
}
