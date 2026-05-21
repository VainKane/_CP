#include <iostream>

int n;
int m;

int main()
{
	std::cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cout << '#';
		}

		if (i == n - 1)
		{
			continue;
		}

		std::cout << '\n';
	}
}