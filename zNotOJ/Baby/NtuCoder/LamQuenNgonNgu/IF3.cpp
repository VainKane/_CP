#include <bits/stdc++.h>

using namespace std;

bool Check (long long year)
{
    if (year % 400 == 0)
    {
        return true;
    }
    if (year % 4 == 0 && year % 100 != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

long long year;

int main()
{
    cin >> year;

    if (Check(year))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}