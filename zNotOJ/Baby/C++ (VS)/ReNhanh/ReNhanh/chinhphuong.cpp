#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int num;

int main()
{
	freopen("chinhphuong.inp", "r", stdin);
	freopen("chinhphuong.out", "w", stdout);

	cin >> num;

	if ((int)sqrt(num) * (int)sqrt(num) == num)
	{
		cout << "yes";
	}
	else
	{
		cout << "no";
	}

}