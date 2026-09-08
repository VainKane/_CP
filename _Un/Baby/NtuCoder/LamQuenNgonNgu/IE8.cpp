#include <bits/stdc++.h>

using namespace std;

string Solve(int a, int b, int c)
{
    if (b != 0)
    {
        if (a / b == c)
        {
            return "/";    
        }
    }
    if (c != 0)
    {
        if (b / c == a)
        {
            return "/";
        }
    }
    if (a != 0)
    {
        if (c / a == b)
        {
            return "/";
        }
    }

    return "NOSOL";
}

int a;
int b;
int c;

int main()
{
    cin >> a >> b >> c;

    cout << Solve(a, b, c);
}