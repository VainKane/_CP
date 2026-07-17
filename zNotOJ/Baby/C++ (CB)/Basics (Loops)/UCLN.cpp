#include <bits/stdc++.h>

int n;
int m;

int result;

int main()
{


	std::cin >> m >> n;


	m = std::abs(m);
	n = std::abs(n);

	if (m * n == 0)
	{
		result = m + n;
	}
	else
	{
		while (n != m)
		{
			if (m > n)
			{
				m -= n;
			}
			else
			{
				n -= m;
			}
		}

		result = m;
	}

	std::cout << result;
}
