#include <iostream>
#include <cmath>

using namespace std;

int day;
int month;
int year;

bool isLeapYear;
int daysPerMonth;
int daysPerFeb;

int main()
{
	cin >> day >> month >> year;

	if (year % 4 == 0 && year % 100 != 0)
	{
		isLeapYear = true;
	}
	if (year % 400 == 0)
	{
		isLeapYear = true;
	}

	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		daysPerMonth = 31;
	}
	else if (month != 2)
	{
		daysPerMonth = 30;
	}


	if (isLeapYear == true)
	{
		daysPerFeb = 29;
	}
	else
	{
		daysPerFeb = 28;
	}


	if (month == 2)
	{
		if (day < daysPerFeb)
		{
			day += 1;
		}
		else
		{
			day = 1;
			month += 1;
		}
	}
	else if (month == 12)
	{
		if (day < daysPerMonth)
		{
			day += 1;
		}
		else
		{
			day = 1;
			month = 1;
			year += 1;
		}
	}
	else
	{
		if (day < daysPerMonth)
		{
			day += 1;
		}
		else
		{
			day = 1;
			month += 1;
		}
	}

	cout << day << " " << month << " " << year;
}