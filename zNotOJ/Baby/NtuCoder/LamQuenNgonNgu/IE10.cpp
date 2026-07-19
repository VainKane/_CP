#include <bits/stdc++.h>

using namespace std;

int day1;
int month1;
int year1;

int day2;
int month2;
int year2;

int main()
{
    cin >> day1 >> month1 >> year1;
    cin >> day2 >> month2 >> year2;

    if (year1 < year2)
    {
        cout << 1;
    }
    else if (year1 > year2)
    {
        cout << -1;
    }
    else
    {
        if (month1 < month2)
        {
            cout << 1;
        }
        else if (month1 > month2)
        {
            cout << -1;
        }
        else
        {
            if (day1 < day2)
            {
                cout << 1;
            }
            else if (day1 > day2)
            {
                cout << -1;
            }
            else
            {
                cout << 0;
            }
        }
    }
}