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

int const N = 5e5 + 5;

int n, t, s;
pair<int, int> a[N];
int p[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> t >> s;
    
    FOR(i, 1, n)
    {
        cin >> a[i].F;
        a[i].S = i;
    }

    FOR(i, 1, n) cin >> p[i];

    sort(a + 1, a + n + 1);

    int haha = 0;
    long long res = 0;
    int idx = 0;

    FOR(i, 1, n) if (t >= a[i].F)
    {
        haha += a[i].F;
        t -= a[i].F;

        if (s < haha) continue;

        res += 1LL * p[1] * (s - haha);
        idx = i;
    }

    cout << idx << ' ' << res << '\n';
    FOR(i, 1, idx) cout << a[i].S << ' ';

    return 0;
}