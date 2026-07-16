#include <bits/stdc++.h>

using namespace std;

long long LuyThua(int a, int b)
{
    long long res = 1;

    while (b)
    {
        if (b % 2 == 1)
        {
            res *= a;
        }

        b /= 2;
        a *= a;
    }

    return res;
}

int n;

int main()
{
    cin >> n;
    
    cout << LuyThua(2, n);
}