#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1ll << (i))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second
#define name "remk"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 3e5 + 5;
int const M = 1e6 + 5;

int n, k;
pair<int, int> a[N];

int cnt[M], cntDiv[M];
int res[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> k;
    FOR(i, 1, n) 
    {
        int x; cin >> x;
        a[i] = {x, i};
        cnt[x]++;
    }

    FOR(i, k + 1, 1e6) if (i != k) for (int j = i; j <= 1e6; j += i)
    {
        cntDiv[j] += cnt[i];
    }

    sort(a + 1, a + n + 1, greater<pair<int, int>> ());

    FOR(i, 1, n)
    {
        if (a[i].F > k) res[a[i].S] = cntDiv[a[i].F - k];
        else if (a[i].F == k) res[a[i].S] = i - 1;
    }

    FOR(i, 1, n) cout << res[i] << ' ';
    // cout << cntDiv[5];

    return 0;
}