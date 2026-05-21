#include <iostream>

int n;
int count;

int main()
{
	std::cin >> n;

	count = n;

	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < count; i++)
		{
			std::cout << '*';
		}

		count -= 1;
		
		if (j != n - 1)
		{
			std::cout << '\n';
		}
	}
	
}