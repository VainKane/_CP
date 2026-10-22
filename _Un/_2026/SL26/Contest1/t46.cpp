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

int const N = 5e5 + 5;

int n, m, k, r;
vector<int> adj[N];

vector<int> par;
int sz[N];

int cnt[N];

ll res[N];

ll C2(int x) { return 1LL * x * (x - 1) / 2; }

int Get(int k)
{
    int idx = sz(par) - 1 - k;
    return idx >= 0 ? par[idx] : 0;
}

void DFSPrepare(int u, int p)
{
    sz[u] = 1;
    for (auto &v : adj[u]) if (v != p) DFSPrepare(v, u), sz[u] += sz[v];
}

void DFS(int u, int p)
{
    par.push_back(u);

    for (auto &v : adj[u]) if (v != p) DFS(v, u);

    int t = Get(m + 1);

    if (m + 1 <= k) res[t] += 1LL * sz[u] * (n - sz[t]);
    cnt[Get(m + 1 - r)] += sz[u];
    par.pop_back();
}

void DFS1(int u, int p)
{
    par.push_back(u);
    for (auto &v : adj[u]) if (v != p) DFS1(v, u);

    res[Get(r)] += C2(cnt[u]);
    par.pop_back();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    FOR(i, 2, n)
    {
        int p; cin >> p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }

    r = (2 * m + 2 - k) / 2;

    DFSPrepare(1, -1);
    DFS(1, -1);
    DFS1(1, -1);

    FOR(u, 1, n) cout << res[u] + C2(n - sz[u]) << ' ';

    return 0;
}