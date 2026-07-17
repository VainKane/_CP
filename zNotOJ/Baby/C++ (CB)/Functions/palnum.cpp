#include <bits/stdc++.h>

int Reverse(int n);


int n;

int main()
{
	std::cin >> n;

	while (n != Reverse(n))
	{
		n += Reverse(n);
	}

	std::cout << n;
}

int Reverse(int n)
{
	int result = n % 10;
	//n /= 10;

	while (n > 0)
	{
		n /= 10;

		result *= 10;
		result += n % 10;
	}

	result /= 10;

	return result;
}
