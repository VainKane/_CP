#include <bits/stdc++.h>

int n;
int count;
int sum;

int main()
{
	std::cin >> n;

	while (n > 0)
	{
		sum += n % 10;

		n /= 10;

		count += 1;
	}

	std::cout << count << ' ' << sum;
}
