#include <bits/stdc++.h>

using namespace std;

long long a;
long long b;
long long c;

long long delta;

int main()
{   
    cin >> a >> b >> c;

    delta = b * b - 4 * a * c;

    if (delta > 0)
    {
        cout << "TWO";
    }
    else if (delta < 0)
    {
        cout << "NOSOL";
    }
    else
    {
        cout << "ONE";
    }
}