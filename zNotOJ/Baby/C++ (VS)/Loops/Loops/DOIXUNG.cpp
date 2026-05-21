#include <iostream>

int Count(int n);
int Reverse(int n);

int n;

int main()
{
	std::cin >> n;

	if (n == Reverse(n))
	{
		std::cout << "YES";
	}
	else
	{
		std::cout << "NO";
	}
}

int Count(int n)
{
	int count = 0;

	while (n > 0)
	{
		count += 1;
		n /= 10;
	}

	return count;
}

int Reverse(int n)
{
	int result = 0;

	for (int i = Count(n); i > 0; i--)
	{
		result += (n % 10) * pow(10, Count(n) - 1);
		n /= 10;
	}

	return result;
}

