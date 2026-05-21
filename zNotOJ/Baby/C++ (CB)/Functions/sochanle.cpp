#include <iostream>

int Count(long long n);
std::string Check(long long n);


long long n;

int main()
{
	std::cin >> n;

	std::cout << Check(n);
}

int Count(long long n)
{
	int count = 0;

	while (n > 0)
	{
		n /= 10;
		count += 1;
	}

	return count;
}

std::string Check(long long n)
{
	std::string result = "YES";

	for (int i = Count(n); i > 0; i--)
	{
		if (i % 2 == 0 && (n % 10) % 2 == 1)
		{
			result = "NO";
			break;
		}
		else if (i % 2 == 1 && (n % 10) % 2 == 0)
		{
			result = "NO";
			break;
		}

		n /= 10;
	}

	return result;
}