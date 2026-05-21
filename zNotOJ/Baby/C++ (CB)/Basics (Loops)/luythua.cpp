#include <bits/stdc++.h>

int n;
int x;
long long result;

int main()
{
	std::cin >> n >> x;

	result = 1;

	for (int i = 0; i < x; i++)
	{
		result *= n;
	}

	std::cout << result;
}