#include <bits/stdc++.h>

using namespace std;

bool Check(long long a, long long b, long long c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return false;
    }
    else
    {
        if (a + b > c && b + c > a && a + c > b)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

long long a;
long long b;
long long c;

int main()
{
    cin >> a >> b >> c;

    if (Check(a, b, c))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}