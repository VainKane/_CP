#include <iostream>
#include <cmath>
#include <string>

int a;
int b;
int c;

int max;

void Sort(int a, int b, int c, int& minOut, int& midOut, int& maxOut);


int main()
{

	std::cin >> a >> b >> c;

	Sort(a, b, c, a, b, c);

	max = c - b > b - a ? c - b : b - a;

	std::cout << max - 1;
}

void Sort(int a, int b, int c, int& minOut, int& midOut, int& maxOut)
{
	minOut = a;
	maxOut = a;

	if (minOut > b)
	{
		minOut = b;
	}
	if (minOut > c)
	{
		minOut = c;
	}


	if (maxOut < b)
	{
		maxOut = b;
	}
	if (maxOut < c)
	{
		maxOut = c;
	}

	midOut = a + b + c - minOut - maxOut;
}