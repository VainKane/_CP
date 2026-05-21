#include <iostream>
#include <cmath>

int n;

bool isPrime = true;

int main()
{
	std::cin >> n;

	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			isPrime = false;
			break;
		}
	}

	if (isPrime == true && n > 1)
	{
		std::cout << "YES";
	}
	else
	{
		std::cout << "NO";
	}
}
