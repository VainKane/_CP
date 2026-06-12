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
#define name ""

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 1e5 + 5;
int const os = 1e9 + 9;
ll const oo = 6e18;

int n, q;
int t[N], v[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> t[i] >> v[i], v[i] = abs(v[i]), assert(v[i]);
    
    while (q--)
    {
        int tt; cin >> tt;

        pair<ll, int> res = {oo, -1};
        FOR(i, 1, n) if (t[i] <= tt)
        {
            ll dist = 1LL * (tt - t[i]) * v[i];
            if (res.F == dist && v[i] > v[res.S]) res.S = i;
            else mini(res, {dist, i});
        }

        if (res.S != -1)
        {
            assert(res.S >= 1 && res.S <= n);
            assert(res.F >= 0);

            ll dist = 1LL * (tt - t[res.S]) * v[res.S];
            FOR(i, 1, n) if (t[i] <= tt) assert(1LL * (tt - t[i]) * v[i] >= dist);
        }
        else assert(*min_element(t + 1, t + n + 1) > tt);

        cout << res.S << ' ';
    }

    return 0;
}