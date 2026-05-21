#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

void Sort(int a, int b, int c, int& minOut, int& midOut, int& maxOut);

int a;
int b;
int c;

int missingNum;

int congSai;

int main()
{
	cin >> a >> b >> c;

	Sort(a, b, c, a, b, c);

	if (b - a == c - b)
	{
		congSai = b - a;
		missingNum = c + congSai;
	}
	else if (c - b < b - a)
	{
		congSai = c - b;
		missingNum = a + congSai;
	}
	else if (b - a < c - b)
	{
		congSai = b - a;
		missingNum = b + congSai;
	}

	cout << missingNum;
}

void Sort(int a, int b, int c, int& minOut, int& midOut, int &maxOut)
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