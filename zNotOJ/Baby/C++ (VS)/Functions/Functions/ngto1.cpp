#include <iostream>
#include <string>

int CDCount(int n);
std::string PrimeCheck(int n);


long long n;

int main()
{
	std::cin >> n;

	std::cout << PrimeCheck(CDCount(n));
}

int CDCount(int n)
{
	int count = 0;

	for (int i = 1; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			if (i != sqrt(n))
			{
				count += 2;
			}
			else
			{
				count += 1;
			}
		}
	}

	return count;
}

std::string PrimeCheck(int n)
{
	std::string result;

	if (n > 1)
	{
		result = "YES";
	}
	else
	{
		result = "NO";
	}

	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			result = "NO";
			break;
		}
	}

	return result;
}