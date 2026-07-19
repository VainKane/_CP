#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 1e6 + 5;

int n, k;
int d[N];
long long h[N];

void Solve(int k)
{
    if (k == 1) return;

    int hMax = h[k] - d[k];
    int j = k - 1;

    while (d[j] <= 0 && j >= 2)
    {
        h[j] = d[j] + hMax;
        j--;
    }
    
    h[j] = hMax;
    Solve(j);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k >> h[k];
    FOR(i, 2, n) cin >> d[i];

    Solve(k);
    if (k != 1) h[1] = h[2] - d[2];

    long long ma = h[1];
    FOR(i, 1, k) maxi(ma, h[i]);

    FOR(i, k + 1, n)
    {
        h[i] = d[i] + ma;
        maxi(ma, h[i]);
    }

    FOR(i, 1, n) cout << h[i] << ' ';

    return 0;
}