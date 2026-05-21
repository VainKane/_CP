#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>


std::string CMFind(int m, int n);

int m;
int n;

int main()
{
	/*freopen("boichung.inp", "r", stdin);
	freopen("boichung.out", "w", stdout);*/
		
	std::cin >> m >> n;

	std::cout << CMFind(m, n);
}

std::string CMFind(int m, int n)
{
	std::string result;

	for (int i = std::max(m, n); i <= m * n; i += std::max(m, n))
	{
		if (i % std::min(m, n) == 0)
		{
			result += std::to_string(i) + " ";
		}
	}

	result.erase(result.length() - 1);

	return result;
}

