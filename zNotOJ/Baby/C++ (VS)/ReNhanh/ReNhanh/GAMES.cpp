#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>

using namespace std;


int bacChoice;
int namChoice;

int main()
{
	freopen("GAMES.inp", "r", stdin);
	freopen("GAMES.out", "w", stdout);

	cin >> bacChoice >> namChoice;
	
	if (bacChoice == namChoice)
	{
		cout << "HOA";
	}
	
	else if (bacChoice == 0)
	{
		if (namChoice == 1)
		{
			cout << "BAC";
		}
		else
		{
			cout << "NAM";
		}
	}

	else if (bacChoice == 1)
	{
		if (namChoice == 2)
		{
			cout << "BAC";
		}
		else
		{
			cout << "NAM";
		}
	}

	else if (bacChoice == 2)
	{
		if (namChoice == 0)
		{
			cout << "BAC";
		}
		else
		{
			cout << "NAM";
		}
	}
}