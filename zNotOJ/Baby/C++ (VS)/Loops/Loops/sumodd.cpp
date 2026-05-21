#include <iostream>

int n;
int sum;

int main()
{
	std::cin >> n;

	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 1)
		{
			sum += i;
		}
	}

	std::cout << sum;
}