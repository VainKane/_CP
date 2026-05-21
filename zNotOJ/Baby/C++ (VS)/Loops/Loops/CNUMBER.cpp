#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <stdio.h>
#include <string>


bool Check(int n);
std::string result;

long long n;

int main()
{
	/*freopen("CNUMBER.inp", "r", stdin);
	freopen("CNUMBER.out", "w", stdout);*/

	std::cin >> n;

	for (int i = 6; i <= n; i++)
	{
		if (Check(i) == true)
		{
			result += std::to_string(i) + " ";
		}
	}

	result.erase(result.length() - 1);

	std::cout << result;
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
		if (n % 10 == 6 || n % 10 == 8)
		{
		}
		else
		{
			result = false;
			break;
		}

		n /= 10;
	}

	return result;
}