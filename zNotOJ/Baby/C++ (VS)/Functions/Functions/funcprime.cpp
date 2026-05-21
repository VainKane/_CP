#include <iostream>
#include <string>

void Sieve(int n);
int Sum(int n);


bool prime[1000000001];
int n;


int main()
{
	std::cin >> n;

	Sieve(n);
	Sieve(Sum(n));

	if (prime[Sum(n)] == true)
	{
		std::cout << "YES";
	}
	else
	{
		std::cout << "NO";
	}
}


void Sieve(int n)
{
	std::string result;


	for (int i = 0; i < 1000000001; i++)
	{
		prime[i] = true;
	}

	prime[0] = prime[1] = false;

	for (int i = 2; i <= sqrt(n); i++)
	{
		if (prime[i] == true)
		{
			for (int j = i * i; j <= n; j += i)
			{
				prime[j] = false;
			}
		}
	}
}

int Sum(int n)
{
	int sum = 0;

	for (int i = 2; i <= n; i++)
	{
		if (prime[i] == true)
		{
			sum += i;
		}
	}

	return sum;
}