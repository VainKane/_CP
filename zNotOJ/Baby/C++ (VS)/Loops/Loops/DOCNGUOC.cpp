#include <iostream>
#include <string>
#include <algorithm>

int Count(int num);
int Reverse(int num);

int num1;
int num2;

int main()
{
	std::cin >> num1 >> num2;

	std::cout << std::max(Reverse(num1), Reverse(num2));
}


int Count(int num)
{
	int count = 0;

	while (num > 0)
	{
		count += 1;
		num /= 10;
		
	}

	return count;
}

int Reverse(int num)
{
	int reversedNum = 0;

	for (int i = Count(num); i > 0; i--)
	{
		reversedNum += (num % 10) * std::pow(10, Count(num) - 1);
		num /= 10;
	}

	return reversedNum;
}