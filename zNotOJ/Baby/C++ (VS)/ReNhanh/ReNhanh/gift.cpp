#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <stdio.h>

using namespace std;

int n;

int main()
{
	freopen("gift.inp", "r", stdin);
	freopen("gift.out", "w", stdout);

	cin >> n;

	if (n % 2 == 0)
	{
		cout << n / 2 << " " << n / 2;
	}
	else
	{
		cout << n / 2 << " " << n / 2 + 1;
	}
}
