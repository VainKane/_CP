#include <iostream>
#include <cmath>

using namespace std;

void MinMaxFind(int a, int b, int c, int d, int e);

unsigned int a;
unsigned int b;
unsigned int c;
unsigned int d;
unsigned int e;

int sum;

int main()
{
	cin >> a >> b >> c >> d >> e;

	sum = a + b + c + d + e;

	MinMaxFind(sum - a, sum - b, sum - c, sum - d, sum - e);
}

void MinMaxFind(int a, int b, int c, int d, int e)
{
	int min;
	int max;

	min = a;
	max = a;

	if (min >= b)
	{
		min = b;
	}
	if (min >= c)
	{
		min = c;
	}
	if (min >= d)
	{
		min = d;
	}
	if (min >= e)
	{
		min = e;
	}


	if (max <= b)
	{
		max = b;
	}
	if (max <= c)
	{
		max = c;
	}
	if (max <= d)
	{
		max = d;
	}
	if (max <= e)
	{
		max = e;
	}

	cout << min << " " << max;
}