#include <iostream>
#include <cmath>

int n;
long long sum;

int main()
{
	std::cin >> n;

	sum = 0;

	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
            if (i != sqrt(n))
            {
			    sum += (long long)i + (n / i);
            }
            else
            {
                sum += (long long)i;
            }
		}
	}

	if (n < sum)
	{
		std::cout << 1;
	}
	else
	{
		std::cout << 0;
	}
}