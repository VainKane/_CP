#include <bits/stdc++.h>

long long n;

int main()
{
	std::cin >> n;

    std::cout << 2;

	for (int i = 4; i <= n; i++)
	{
		if (i % 2 == 0)
		{
			std::cout << ' ' << i;
		}
	}

}
