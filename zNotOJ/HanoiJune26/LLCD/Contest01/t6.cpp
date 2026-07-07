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

bool prime[N];
vector<int> facts[N], divs[N];

int in[N], out[N];
int node[N], bigChild[N];
int timer = 0;

int cnt[N];
ll d[N], s[N];

pair<ll, ll> res;

void Sieve()
{
    memset(prime, 1, sizeof prime);
    prime[0] = prime[1] = 0;

    FOR(i, 2, sqrt(n)) if (prime[i]) for (int j = i * i; j <= n; j += i) prime[j] = false;
    FOR(i, 1, sqrt(n)) for (int j = i * i; j <= n; j += i)
    {
        divs[j].push_back(i);
        if (prime[i]) facts[j].push_back(i);

        if (i * i != j)
        {
            if (prime[j / i]) facts[j].push_back(j / i);
            divs[j].push_back(j / i);
        }
    }
}

void DFSPrepare(int u, int p)
{
    in[u] = ++timer;
    node[timer] = u;
    int sz = 0;

    for (auto &e : adj[u])
    {
        int v = e.F, w = e.S;
        if (v == p) continue;

        d[v] = d[u] + w;
        DFSPrepare(v, u);
        if (maxi(sz, out[v] - in[v] + 1)) bigChild[u] = v;
    }

    out[u] = timer;
}

void UpdateRes(int v, int u)
{
    ll sum = 0;
    int k = 0;

    REP(mask, MK(sz(facts[v])))
    {
        int delta = __builtin_parity(mask) ? -1 : 1;
        
        int lcm = 1;
        for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
        {
            int i = __builtin_ctz(tmp);
            lcm *= facts[v][i];
        }

        sum += delta * s[lcm];
        k += delta * cnt[lcm];
    }

    res.F += sum + k * (d[v] - 2 * d[u]);
    res.S += k;
}

void DFS(int u, int p)
{
    for (auto &e : adj[u])
    {
        int v = e.F, w = e.S;
        if (v == p || v == bigChild[u]) continue;
        
        DFS(v, u);
        FOR(i, in[v], out[v]) for (auto &x : divs[node[i]]) cnt[x] = s[x] = 0;
    }

    if (bigChild[u]) DFS(bigChild[u], u);
    for (auto &e : adj[u])
    {
        int v = e.F;
        if (v == p || v == bigChild[u]) continue;

        FOR(i, in[v], out[v]) UpdateRes(node[i], u);

        FOR(i, in[v], out[v]) for (auto &x : divs[node[i]])
            s[x] += d[node[i]], cnt[x]++;
    }

    UpdateRes(u, u);
    for (auto &x : divs[u]) s[x] += d[u], cnt[x]++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 2, n)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    Sieve();
    DFSPrepare(1, -1);
    DFS(1, -1);

    cout << fixed << setprecision(6) << (double)res.F / res.S;

    return 0;
}