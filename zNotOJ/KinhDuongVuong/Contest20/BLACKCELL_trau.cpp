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

int n, m, q;
vector<pair<int, int>> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> n >> m >> q;
    FOR(i, 1, q)
    {
        int type, x1, y1, x2, y2;
        cin >> type >> x1 >> y1 >> x2 >> y2;

        if (type == 1) FOR(x, x1, x2) v.push_back({x, y1});
        else if (type == 2) FOR(y, y1, y2) v.push_back({x1, y});
        else FOR(d, 0, x2 - x1) v.push_back({x1 + d, y1 + d});
    }

    sort(all(v));
    v.erase(unique(all(v)), v.end());

    cout << sz(v);

    return 0;
}
