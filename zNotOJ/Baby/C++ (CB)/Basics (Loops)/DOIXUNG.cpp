#include <bits/stdc++.h>

int Reverse(int n);

int n;

int main()
{
	std::cin >> n;

	if (n == Reverse(n))
	{
		std::cout << "YES";
	}
	else
	{
		std::cout << "NO";
	}
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
