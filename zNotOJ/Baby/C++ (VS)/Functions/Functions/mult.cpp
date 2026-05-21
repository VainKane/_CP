#include <iostream>

int Multi(int a, int b);


int a;
int b;

int main()
{
	std::cin >> a >> b;

	std::cout << Multi(a, b);
}

int Multi(int a, int b)
{
	int result = 0;

	int bClone = b;

	while (a > 0)
	{
		while (bClone > 0)
		{
			result += (bClone % 10) * (a % 10);
			bClone /= 10;
		}

		a /= 10;
		bClone = b;
	}

	return result;
}