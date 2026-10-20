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

int n;
vector<ii> adj[N];

ll f[N];

vector<ll> d;
ll suf[N];

ll sum = 0;

void DFS(int u, int p)
{
    f[u] = 0;
    for (auto &e : adj[u])
    {
        int v = e.F, w = e.S;
        if (v == p) continue;

        DFS(v, u);
        maxi(f[u], f[v] + w);
    }

    for (auto &e : adj[u])
    {
        int v = e.F, w = e.S;
        if (v == p) continue;
        if (f[v] && f[v] + w != f[u]) d.push_back(f[v] + w);
    }
}

void Reset()
{
    FOR(u, 1, n) adj[u].clear();
    d.clear();
    sum = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n;
        Reset();
        FOR(i, 2, n)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
            sum += w;
        }

        DFS(1, -1);
        sort(all(d));

        suf[sz(d)] = 0;
        FORD(i, sz(d) - 1, 0) suf[i] = suf[i + 1] + d[i];

        sum = 2 * sum - f[1];

        int q; cin >> q;
        while (q--)
        {
            int p; cin >> p;
            int idx = upper_bound(all(d), p) - d.begin();
            cout << sum + 1LL * (sz(d) - idx) * p - suf[idx] << '\n';
        }
    }

    return 0;
}