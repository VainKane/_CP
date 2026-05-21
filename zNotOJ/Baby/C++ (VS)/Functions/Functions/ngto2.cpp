#include <iostream>
#include <string>

int Sum(int n);
std::string Check(int n);

int n;

int main()
{
	std::cin >> n;

	std::cout << Check(Sum(n));
}

int Sum(int n)
{
	int sum = 0;

	while (n > 0)
	{
		sum += n % 10;

		n /= 10;
	}

	return sum;
}

std::string Check(int n)
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