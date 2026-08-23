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
ll const oo = 1e18 + 9;

int n;

int a[N];
vector<int> adj[N];

bool leaf[N];
int cnt[N];

ll d[N], dPar[N];

void DFSPrepare(int u, int p)
{
    cnt[u] = leaf[u];

    for (auto &v : adj[u]) if (v != p)
    {
        DFSPrepare(v, u);
        cnt[u] += cnt[v];
        d[u] += d[v] + 1LL * cnt[v] * (a[v] + !leaf[v]);
    }
}

void DFS(int u, int p)
{
    for (auto &v : adj[u]) if (v != p)
    {
        dPar[v] = dPar[u] + d[u] - d[v] - 1LL * cnt[v] * (a[v] + !leaf[v]) + 3 * (cnt[1] - cnt[v]);
        DFS(v, u);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n)
    {
        string s; cin >> s;
        a[i] = sz(s);

        int k; cin >> k;
        leaf[i] = !k;

        while (k--)
        {
            int u; cin >> u;
            adj[i].push_back(u);
            adj[u].push_back(i);
        }
    }

    DFSPrepare(1, -1);
    DFS(1, -1);

    ll res = oo;
    FOR(u, 1, n) if (!leaf[u]) mini(res, d[u] + dPar[u]);
    cout << res;

    return 0;
}