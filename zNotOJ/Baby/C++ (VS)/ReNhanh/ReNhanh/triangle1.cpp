#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int a;
int b;
int c;

string result;

int main()
{
	freopen("triangle1.inp", "r", stdin);
	freopen("triangle1.out", "w", stdout);

	cin >> a >> b >> c;

	if ((a < b + c) && (b < a + c) && (c < a + b))
	{
		result = "YES";
	}
	else
	{
		result = "NO";
	}

	cout << result;
}