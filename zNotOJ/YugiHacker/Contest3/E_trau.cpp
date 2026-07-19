#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define F first
#define S second

template <class t> mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1e5 + 5;
long long const oo = 8e18;

int n;
pair<int, int> a[N];

long long Dist(pair<int, int> a, pair<int, int> b)
{
    int x = a.F - b.F;
    int y = a.S - b.S;

    return 1ll * x * x + 1ll * y * y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("E.inp", "r", stdin);

    cin >> n;
    FOR(i, 1, n) cin >> a[i].F >> a[i].S;

    long long res = oo;
    FOR(i, 1, n) FOR(j, i + 1, n) mini(res, Dist(a[i], a[j]));
    cout << res;

    return 0;
}