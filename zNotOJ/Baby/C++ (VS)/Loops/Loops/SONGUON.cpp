#include <iostream>

int Sum(int num);

int m;
int n;

int result;

int main()
{
	std::cin >> m;

	result = m;

	for (int sum = 0; sum <= 82; sum++)
	{
		n = m - sum;

		if (Sum(n) == sum)
		{
			result = std::min(result, n);
		}
	}

	if (result == m)
	{
		result = -1;
	}

	std::cout << result;
}

int Sum(int num)
{
	int sum = 0;

	//num = std::abs(num);

	while (num > 0)
	{
		sum += num % 10;
		num /= 10;
	}

	return sum;
}

