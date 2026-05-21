#include <iostream>

int n;

int main()
{
	std::cin >> n;

	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 0)
		{
			std::cout << i << ' ';
		}
	}
}
