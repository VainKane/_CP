#include <bits/stdc++.h>

using namespace std;

int Solve( long double target)
{
    int n = 2;

    long double sum = 1;

    while (true)
    {
        sum += 1 / (long double)n;

        if (sum >= target)
        {
            return n;
        }

        n += 1;
    }
}

long double target;

int main()
{
    cin >> target;

    cout << Solve(target);
}