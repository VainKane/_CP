#include <bits/stdc++.h>

bool Check(int year);


int year;

int main()
{
	std::cin >> year;

	year += 1;

	while (Check(year) == false)
	{
		year += 1;
	}

	std::cout << year;
}

bool Check(int year)
{
	bool result = true;
	int nums[4];

	for (int i = 0; i < 4; i++)
	{
		nums[i] = year % 10;
		year /= 10;
	}
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i != j && nums[i] == nums[j])
			{
				result = false;
				break;
			}
		}
	}

	return result;

}