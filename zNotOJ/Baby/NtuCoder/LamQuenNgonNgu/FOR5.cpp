#include <bits/stdc++.h>

using namespace std;

int n;

long long res = 1;

int main()
{
    cin >> n;

    for (int i = 2; i <= n; i++)
    {
        res *= i;
        res %= 1000000007;
    }

    cout << res;
}