#include <bits/stdc++.h>

using namespace std;

#define name "DONGNUOC"

long long n;

long long Solve()
{   
    long long res = n / 5;
    int r = n % 5;

    if (!r) return res;
    res++;
    if (r == 4) res++;

    return res;
}

int main()
{
    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    cout << Solve();
}