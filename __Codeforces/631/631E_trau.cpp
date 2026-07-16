#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1LL << (i))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 2e5 + 5;

int n;
int a[N];

long long Cost()
{
    long long res = 0;
    FOR(i, 1, n) res += 1LL * i * a[i];
    return res;
}

void SwapDown(int st, int ed)
{
    FORD(i, st, ed + 1) swap(a[i], a[i - 1]);
}

void SwapUp(int st, int ed)
{
    FOR(i, st, ed - 1) swap(a[i], a[i + 1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    long long res = -1e18;
    pair<int, int> p;

    FOR(i, 1, n) FOR(j, i, n)
    {
        SwapDown(j, i);
        if (maxi(res, Cost())) p = {j, i};
        SwapUp(i, j);
    }

    FOR(i, 1, n) FOR(j, i, n)
    {
        SwapUp(i, j);
        if (maxi(res, Cost())) p = {i, j};
        SwapDown(j, i);
    }

    // cout << p.F << ' ' << p.S << '\n';
    cout << res;

    return 0;
}