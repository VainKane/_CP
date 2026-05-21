#include <bits/stdc++.h>

int Sum(int n);


int a;
int b;

int main()
{
	std::cin >> a >> b;

	if (Sum(a) == b && Sum(b) == a)
	{
		std::cout << "YES";
	}
	else
	{
		std::cout << "NO";
	}
}

int Sum(int n)
{
	int sum = 1;

	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			sum += (i + (n / i));
		}
		if (i == sqrt(n))
		{
			sum -= i;
		}
	}


	return sum;
}