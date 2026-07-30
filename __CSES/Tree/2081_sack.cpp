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

int in[N], out[N];
int node[N], bigChild[N];
int timer = 0;

int h[N], maxH[N];
int cnt[N], c[N];

ll res = 0;
int iniSum = 0;

void DFSPrepare(int u, int p)
{
    in[u] = ++timer;
    node[timer] = u;
    maxH[u] = h[u];
    int sz = 0;

    for (auto &v : adj[u]) if (v != p)
    {
        h[v] = h[u] + 1;
        DFSPrepare(v, u);

        if (maxi(sz, out[v] - in[v] + 1)) bigChild[u] = v;
        maxi(maxH[u], maxH[v]);
    }

    out[u] = timer;
}

int Val(int x)
{
    if (x < 0 || x > n) return 0;
    return cnt[x];
}

void DFS(int u, int p)
{
    for (auto &v : adj[u]) if (v != p && v != bigChild[u])
    {
        DFS(v, u);
        FOR(i, in[v], out[v]) cnt[h[node[i]]] = 0;
    }

    iniSum = 0;
    if (bigChild[u]) DFS(bigChild[u], u);
    int sum = 0;

    for (auto &v : adj[u]) if (v != p && v != bigChild[u])
    {
        FOR(i, in[v], out[v]) c[h[node[i]]]++;

        sum = iniSum;
        
        sum = 0;
        FOR(i, l + 2 * h[u], min(n, r + 2 * h[u])) sum += cnt[i];

        FOR(i, h[v], maxH[v])
        {
            sum += Val(l - i + 2 * h[u]);
            sum -= Val(r - i + 2 * h[u] + 1);

            if (l + 2 * h[u] <= i && i <= r + 2 * h[u]) iniSum += c[i];
            res += 1LL * c[i] * sum;
        }

        FOR(i, in[v], out[v]) cnt[h[node[i]]]++, c[h[node[i]]] = 0;
    }

    FOR(i, l + h[u], min(r + h[u], n)) res += cnt[i];
    // res += iniSum;
    cnt[h[u]]++;
    iniSum++;
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

    DFSPrepare(1, -1);
    DFS(1, -1);
    cout << res;

    return 0;
}