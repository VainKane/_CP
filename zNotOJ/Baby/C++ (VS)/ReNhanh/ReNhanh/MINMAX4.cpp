#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>

using namespace std;



int main()
{
	int a;
	int b;
	int c;
	int d;

	int min;
	int max;

	cin >> a >> b >> c >> d;

	min = a;
	max = a;
	
	if (min > b)
	{
		min = b;
	}
	if (min > c)
	{
		min = c;
	}
	if (min > d)
	{
		min = d;
	}

	
	if (max < b)
	{
		max = b;
	}
	if (max < c)
	{
		max = c;
	}
	if (max < d)
	{
		max = d;
	}

	cout << min << " " << max;
}