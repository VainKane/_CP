#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int a;
int b;

int main()
{
	cin >> a >> b;

	if (a < b)
	{
		cout << a << " " << b;
	}
	else
	{
		cout << b << " " << a;
	}
}