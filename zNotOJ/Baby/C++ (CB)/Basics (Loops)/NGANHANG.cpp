#include <bits/stdc++.h>

double money;
int goal;
double interest;
int count = 0;

int main()
{
	std::cin >> money >> goal;

	while (money < goal)
	{
		count += 1;

		interest = 0.1 * money;
		money += interest;
	}
	
	std::cout << count;
}