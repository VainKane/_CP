#include <iostream>

int n;
int x;
int result;

int main()
{
	std::cin >> n >> x;

	result = 1;

	for (int i = 0; i < x; i++)
	{
		result *= n;
	}

	std::cout << result;
}