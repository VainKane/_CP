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

int n, l, r;
vector<int> adj[N];

int sz[N];
bool del[N];

int cnt[N], c[N];
ll res = 0;

int maxH;

void DFSPrepare(int u, int p)
{
    sz[u] = 1;
    for (auto &v : adj[u]) if (v != p && !del[v])
    {
        DFSPrepare(v, u);
        sz[u] += sz[v];
    }
}

int Centroid(int u, int p, int n)
{
    for (auto &v : adj[u]) if (v != p && !del[v] && sz[v] > n / 2) return Centroid(v, u, n);
    return u;
}

void DFS(int u, int p, int h, bool add)
{
    if (add) cnt[h]++, c[h] = 0;
    else c[h]++;

    maxi(maxH, h);
    for (auto &v : adj[u]) if (v != p && !del[v]) DFS(v, u, h + 1, add);
}

void Solve(int u)
{
    DFSPrepare(u, -1);
    int cent = Centroid(u, -1, sz[u]);

    del[cent] = 1;
    cnt[0] = 1;

    int sum = 0, iniSum = 0;
    int ma = 0;

    for (auto &v : adj[cent]) if (!del[v])
    {
        maxH = 0;
        DFS(v, cent, 1, false);
        maxi(ma, maxH);

        sum = iniSum;
        FOR(i, 1, maxH)
        {
            if (l - i >= 0) sum += cnt[l - i];
            if (r - i + 1 >= 0) sum -= cnt[r - i + 1];

            if (l <= i && i <= r) iniSum += c[i];
            res += 1LL * c[i] * sum;
        }

        DFS(v, cent, 1, true);
    }

    FOR(i, 1, ma) cnt[i] = 0;
    for (auto &v : adj[cent]) if (!del[v]) Solve(v);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> l >> r;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Solve(1);
    cout << res;

    return 0;
}