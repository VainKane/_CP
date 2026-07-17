#include <bits/stdc++.h>

using namespace std;

int Count(int n)
{
	int count = 0;

	while (n > 0)
	{
		count += n % 10;
		n /= 10;
	}

	return count;
}

int num[60];

int diff = 0;

int l;
int r;

int main()
{
	cin >> l >> r;

	for (int i = 0; i <= 54; i++)
	{
		num[i] = 0;
	}

	for (int i = l; i <= r; i++)
	{
		int value = Count(i);

		if (num[value] == 0)
		{
			num[value] = i;
		}
		else
		{
			if (diff < i - num[value])
			{
				diff = i - num[value];
			}
		}
	}

	cout << diff;
}

