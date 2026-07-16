#include <bits/stdc++.h>

bool Check(int n);

long long count = 0;

long long n;

int main()
{
	// freopen("CNUMBER.inp", "r", stdin);
	// freopen("CNUMBER.out", "w", stdout);

	std::cin >> n;

	for (int i = 6; i <= n; i++)
	{
		if (Check(i) == true)
		{
			count += 1;
		}
	}

	std::cout << count;
}

bool Check(int n)
{
	bool result = true;

	if (n <= 0)
	{
		result = false;
	}

	while (n > 0)
	{
		if (n % 10 != 6 && n % 10 != 8)
		{
            result = false;
            break;
		}

		n /= 10;
	}

	return result;
}