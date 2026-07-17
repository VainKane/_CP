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

int const N = 1e5 + 5;

int k, n;

long long x[N], y[N];
int dx[256], dy[256];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> k >> n;

    dy['N'] = 1, dy['S'] = -1;
    dx['E'] = 1, dx['W'] = -1;

    FOR(i, 1, n)
    {
        char dir; int st;
        cin >> dir >> st;
        
        x[i + 1] = x[i] + dx[dir] * st;
        y[i + 1] = y[i] + dy[dir] * st;
    }

    vector<pair<int, int>> pt;
    FOR(id, 1, n)
    {
        int i = id;
        int j = id + 1;
        if (x[i] > x[j] || y[i] > y[j]) swap(i, j);

        FOR(u, x[i] + 1, x[j] + k) FOR(v, y[i] + 1, y[j] + k) pt.push_back({u, v});
    }

    sort(all(pt));
    pt.erase(unique(all(pt)), pt.end());

    cout << sz(pt);

    return 0;
}