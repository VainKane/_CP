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
int const LOG = 20;

int n, q;

int a[N];
vector<pair<int, string>> adj[N];

int up[2 * N][LOG];
int pos[N];
int timer = 0;

int c2[N], c5[N];
int cnt[N];

int what[N];

bool cmp(int u, int v) { return pos[u] < pos[v]; }

int Count(int x, int base)
{
    int cnt = 0;
    while (x && x % base == 0) x /= base, cnt++;
    return cnt;
}

ii ToInt(string &x)
{
    int res = 0, cnt = 0;
    bool ok = false;

    for (auto &d : x)
    {
        if (d != '.') res = res * 10 + d - '0', cnt += ok;
        else ok = true;
    }

    return {res, cnt};
}

void DFS(int u, int p)
{
    up[++timer][0] = u;
    pos[u] = timer;

    for (auto &e : adj[u])
    {
        int v = e.F;
        if (v == p) continue;

        auto x = ToInt(e.S);

        c2[v] = c2[u] + Count(x.F, 2);
        c5[v] = c5[u] + Count(x.F, 5);
        cnt[v] = cnt[u] + x.S;
        what[v] = what[u] + x.F == 0;

        DFS(v, u);
        up[++timer][0] = u;
    }
}

int LCA(int u, int v)
{
    u = pos[u], v = pos[v];
    if (u > v) swap(u, v);

    int k = 31 - __builtin_clz(v - u + 1);
    return min(up[u][k], up[v - MK(k) + 1][k], cmp);
}

void Init()
{
    FOR(j, 1, 31 - __builtin_clz(timer)) FOR(i, 1, timer - MK(j) + 1)
        up[i][j] = min(up[i][j - 1], up[i + MK(j - 1)][j - 1], cmp);
}

bool Check(int u, int v)
{
    int p = LCA(u, v);
    if (a[u] == 0 || what[u] + what[v] - 2 * what[p] > 0) return true;

    int cnt2 = c2[u] + c2[v] - 2 * c2[p] + Count(a[u], 2);
    int cnt5 = c5[u] + c5[v] - 2 * c5[p] + Count(a[u], 5);

    return min(cnt2, cnt5) >= cnt[u] + cnt[v] - 2 * cnt[p];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 2, n)
    {
        int u, v;
        string w;

        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    DFS(1, -1);
    Init();

    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << (Check(u, v) ? "Yes\n" : "No\n");
    }

    return 0;
}