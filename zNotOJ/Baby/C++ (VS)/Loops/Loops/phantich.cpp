#include <iostream>
#include <cmath>

int n;

int x;
int y;

int main()
{
	std::cin >> n;

	x = 1000000001;
	y = 1000000001;

	// chuong trinh chi dung voi n duong

	for (int i = 1; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			if (i * (n / i) == n)
			{
				if (i + (n / i) < x + y)
				{
					x = i;
					y = n / i;
				}
			}
		}
	}

	std::cout << x << ' ' << y;
}