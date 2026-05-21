#include <iostream>

int PrimeCheck(int n);
long long Sum(int n);

long long Sieve(int n);

bool prime[1000000001];

int n;


int main()
{
	std::cin >> n;
	
	std::cout << Sieve(n);
}

long long Sieve(int n)
{
	long long sum = 0;

	for (int i = 0; i < 1000000001; i++)
	{
		prime[i] = true;
	}

	prime[0] = prime[1] = false;

	for (int i = 2; i <= sqrt(n); i++)
	{
		if (prime[i] == 1)
		{
			for (int j = i * i; j <= n; j += i)
			{
				prime[j] = false;
			}
		}
	}

	for (int i = 0; i <= n; i++)
	{
		if (prime[i] == true)
		{
			sum += i;
		}
	}

	return sum;
}

long long Sum(int n)
{
	long long sum = 0;

	for (int i = 2; i <= n; i++)
	{
		if (PrimeCheck(i) == true)
		{
			sum += i;
		}
	}

	return sum;
}

int PrimeCheck(int n)
{
	bool result;

	if (n > 1)
	{
		result = true;
	}
	else
	{
		result = false;
	}


	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			result = false;
			break;
		}
	}

	return result;
}