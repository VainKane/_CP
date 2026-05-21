#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define F first
#define S second

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 1e5 + 5;

int n;
int a[N];

bool Equal(int l, int r, int u)
{
    REP(i, r - l + 1) if (a[l + i] != a[u + i]) return false;
    return true;
}

int Count(int l, int r)
{
    int k = r - l + 1;
    int res = 0;

    FOR(i, 1, n - k + 1) res += Equal(l, r, i);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    pair<int, int> res = {0, 0};
    int ma = 0;

    FORD(i, n, 1) FOR(j, i, n)
    {
        int tmp = Count(i, j);
        if (maxi(ma, tmp)) res = {i, j}; 
        else if (ma == tmp && res.S - res.F < j - i) res = {i, j};
    }

    cout << res.F << ' ' << res.S;
    // cout << Count(1, 3);

    return 0;
}