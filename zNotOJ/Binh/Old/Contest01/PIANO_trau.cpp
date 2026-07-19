#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "PIANO"

int const N = 1e5 + 5;
int const MOD = 1e9 + 7;

int n, k;
int a[N], x[N];

int res = 0;

void Add(int &x, int y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

void Try(int pos)
{
    if (pos > k)
    {
        int ma = 0;
        FOR(i, 1, n) ma = max(ma, a[x[i]]);

        Add(res, ma);
        return; 
    }

    FOR(i, x[pos - 1] + 1, n - k + pos)
    {
        x[pos] = i;
        Try(pos + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];

    Try(1);
    cout << res;

    return 0;
}