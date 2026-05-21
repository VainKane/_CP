#include <iostream>
#include <algorithm>

int n;
char white;
char black;

int main()
{
	std::cin >> n;

	white = 'W';
	black = 'B';

	for (int j = 1; j <= n * n; j++)
	{
		if (j % 2 == 0)
		{
			std::cout << black;
		}
		else
		{
			std::cout << white;
		}

		if (j == n * n)
		{
			continue;
		}

		if (j % n == 0)
		{
			std::cout << '\n';

			if (n % 2 == 0)
			{
				std::swap(white, black);
			}
		}
	}
}