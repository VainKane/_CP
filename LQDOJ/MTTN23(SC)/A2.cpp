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

int const N = 509;
int const K = 15009;

int n, k, m;
int x[K], y[K], r[K], t[K];
int xs, ys, xt, yt;

bool visited[N][N];

bool Inside(int x, int y)
{
    return  x >= 1 && x <= n &&
            y >= 1 && y <= n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> n >> k >> m;
    FOR(i, 1, k) cin >> x[i] >> y[i] >> r[i] >> t[i];
    cin >> xs >> ys;
    cin >> xt >> yt;

    int res = 0;

    FOR(haha, 0, min(59, m))
    {
        vector<pair<int, int>> pt;
        FOR(i, 1, k)
        {
            FOR(u, -t[i], t[i]) FOR(v, -t[i], t[i])
            {
                if (abs(u) + abs(v) > t[i]) continue;
                if (!Inside(x[i] + u, y[i] + v)) continue;
                pt.push_back({x[i] + u, y[i] + v});
            }
            if (++t[i] == r[i]) t[i] = 0;
        }

        int cnt = 0;
        for (auto &p : pt)
        {
            cnt += !visited[p.F][p.S];
            visited[p.F][p.S] = true;
        }

        for (auto &p : pt) visited[p.F][p.S] = false;
        maxi(res, cnt);
    }

    cout << res;

    return 0;
}