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

int const N = 2e5 + 5;

int n;
vector<int> adj[N];
int a[N];

int h[N];
map<int, pair<int, long long>> mp[N];

ll res = 0;

void DFS(int u, int p)
{
    mp[u][a[u]] = {h[u], 1};

    for (auto &v : adj[u]) if (v != p)
    {
        h[v] = h[u] + 1;
        DFS(v, u);

        if (sz(mp[u]) < sz(mp[v])) swap(mp[u], mp[v]);

        for (auto &val : mp[v])
        {
            auto &x = mp[u][val.F];
            res += 1LL * x.F * val.S.S + 1LL * val.S.F * x.S -2LL * h[u] * x.S * val.S.S;

        }

        for (auto &val : mp[v])
        {
            mp[u][val.F].F += val.S.F;
            mp[u][val.F].S += val.S.S;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >>  v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    FOR(i, 1, n) cin >> a[i];

    DFS(1, -1);
    cout << res;

    return 0;
}