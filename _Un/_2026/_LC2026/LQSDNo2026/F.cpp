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
int const oo = 1e9 + 9;

int n, d;

ii a[N];
vector<int> adj[N];

int up[2 * N][LOG];
int pos[N], h[N];
int timer = 0;

bool leaf[N];
set<int> s;

bool mark[N];

bool cmp(int u, int v) { return pos[u] < pos[v]; }
void DFS(int u, int p)
{
    up[++timer][0] = u;
    pos[u] = timer;

    for (auto &v : adj[u]) if (v != p)
    {
        h[v] = h[u] + 1;
        DFS(v, u);
        up[++timer][0] = u;
    }
}

void Build()
{
    FOR(j, 1, 31 - __builtin_clz(timer)) FOR(i, 1, timer - MK(j) + 1)
        up[i][j] = min(up[i][j - 1], up[i + MK(j - 1)][j - 1], cmp);
}

int LCA(int u, int v)
{
    u = pos[u], v = pos[v];
    if (u > v) swap(u, v);

    int k = 31 - __builtin_clz(v - u + 1);
    return min(up[u][k], up[v - MK(k) + 1][k], cmp);
}

int Dist(int u, int v) { return h[u] + h[v] - 2 * h[LCA(u, v)]; }

int LeftNode(int u)
{
    auto it = s.lower_bound(pos[u]);
    if (it == s.begin()) return 0;

    it--;
    return up[*it][0];
}

int RightNode(int u)
{
    auto it = s.upper_bound(pos[u]);
    if (it == s.end()) return 0;
    return up[*it][0];
}

bool Check(int u)
{
    if (!u) return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> d;
    FOR(i, 1, n) cin >> a[i].F, a[i].S = i;
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        u++, v++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    sort(a + 1, a + n + 1);
    DFS(1, -1);
    Build();
 
    int res = n, j = 1;
    FOR(i, 1, n)
    {
        for (; j <= n && a[j].F - a[i].F <= d; j++)
        {
            int u = a[j].S;
            int v1 = LeftNode(u), v2 = RightNode(u);
            s.erase(pos[u]);

            cur -= Check(v1), cur -= Check(v2);
        }

        s.insert(pos[a[i].S]);
    }

    cout << res;

    return 0;
}