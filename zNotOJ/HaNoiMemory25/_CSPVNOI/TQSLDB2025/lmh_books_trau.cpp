#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define all(v) v.begin(), v.end()

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 1e6 + 5;

int n;
long long m;

int a[N], b[N];
long long suf[N], pre[N];
bool used[N];

bool Check(int u, int v)
{
    if (pre[u] + suf[v] > m) return false;
    memset(used, false, sizeof used);

    FOR(i, 1, u) 
    {
        if (used[a[i]]) return false;
        used[a[i]] = true;
    }

    FOR(i, v, n)
    {
        if (used[a[i]]) return false;
        used[a[i]] = true;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];

    FOR(i, 1, n) pre[i] = pre[i - 1] + b[i];
    FORD(i, n, 1) suf[i] = suf[i + 1] + b[i];

    int res = 0;
    FOR(i, 0, n) FOR(j, i + 1, n + 1) if (Check(i, j)) maxi(res, i + n - j + 1);
    cout << res << '\n';

    return 0;
}