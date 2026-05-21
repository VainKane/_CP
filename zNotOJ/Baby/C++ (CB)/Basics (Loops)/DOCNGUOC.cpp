#include <bits/stdc++.h>

int Reverse(int num);

int num1;
int num2;

int main()
{
	std::cin >> num1 >> num2;

	std::cout << std::max(Reverse(num1), Reverse(num2));
}


int Reverse(int num)
{
	int reversedNum = 0;
	
	while (num > 0)
	{
		reversedNum += num % 10;
		reversedNum *= 10;

		num /= 10;
	}

	reversedNum /= 10;

	return reversedNum;
}