#include <iostream>

char character;
int num;

int main()
{
	std::cin >> character >> num;
	
	for (int i = 0; i < num; i++)
	{
		std::cout << character;
	}
}
