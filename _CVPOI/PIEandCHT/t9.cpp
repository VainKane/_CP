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
int const M = 3e4 + 5;

int n;

int a[N];
vector<int> adj[N];
ll d[N];

bool prime[M];
vector<int> facts[M], divs[M];

int cnt[N];
ll len[N];
ll res = 0;

int in[N], out[N];
int node[N], bigChild[N];
int timer = 0;

void DFSPrepare(int u, int p)
{
    in[u] = ++timer;
    node[timer] = u;
    int sz = 0;

    for (auto &v : adj[u]) if (v != p)
    {
        d[v] = d[u] + a[v];
        DFSPrepare(v, u);
        if (maxi(sz, out[v] - in[v] + 1)) bigChild[u] = v;
    }

    out[u] = timer;
}

void UpdateRes(int v, int u)
{
    int k = 0;
    ll sum = 0;

    FOR(mask, 1, MK(sz(facts[a[u]])) - 1)
    {
        int delta = __builtin_parity(mask) ? 1 : -1;
        
        int lcm = 1;
        for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
        {
            int i = __builtin_ctz(tmp);
            lcm *= facts[v][i];
        }

        sum += delta * len[lcm];
        k += delta * cnt[lcm];
    }

    res += sum + k * (d[v] - 2 * d[u]);
}

void DFS(int u, int p)
{
    for (auto &v : adj[u]) if (v != p && v != bigChild[u])
    {
        DFS(v, u);
        FOR(i, in[v], out[v]) cnt[node[i]] = len[node[i]] = 0;
    }

    if (bigChild[u]) DFS(bigChild[u], u);
    for (auto &v : adj[u]) if (v != p && v != bigChild[u])
    {
        FOR(i, in[v], out[v]) UpdateRes(node[i], u);
        FOR(i, in[v], out[v]) for (auto &x : divs[a[u]]) cnt[x]++, len[x] += d[u];
    }

    for (auto &x : divs[a[u]]) cnt[x]++, len[x] += d[u];
    UpdateRes(u, u);
}

void Sieve()
{
    int lim = *max_element(a + 1, a + n + 1);

    memset(prime, true, sizeof prime);
    prime[0] = prime[1] = false;
    FOR(i, 2, sqrt(lim)) if (prime[i]) for (int j = i * i; j <= lim; j += i) prime[j] = false;

    FOR(i, 1, sqrt(lim)) for (int j = i * i; j <= lim; j += i)
    {
        if (i > 1) divs[j].push_back(i);
        if (prime[i]) facts[j].push_back(i);

        if (i * i == j) continue;
        divs[j].push_back(j / i);
        if (prime[j / i]) facts[j].push_back(j / i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    d[1] = a[1];
    
    Sieve();
    DFSPrepare(1, -1);
    DFS(1, -1);

    cout << res;

    // FOR(i, 1, n)
    // {
    //     cout << a[i] << ":\n";
    //     cout << "facts: ";
    //     for (auto &x : facts[a[i]]) cout << x << ' ';
    //     cout << '\n';
    //     cout << "divs: ";
    //     for (auto &x : divs[a[i]]) cout << x << ' ';
    //     cout << "\n-----------------\n";
    // }

    return 0;
}