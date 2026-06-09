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

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1e5 + 5;
int const M = 3e4 + 5;

int n;

int a[N];
vector<int> adj[N];
long long d[N];

bool prime[M];
vector<int> facts[M], divs[M];

int cnt[N];
long long len[N];
long long res = 0;

int GetLCM(int val, int mask)
{
    int lcm = 1;
    for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
    {
        int i = __builtin_ctz(tmp);
        lcm *= facts[val][i];
    }

    return lcm;
}

void DFS(int u, int p)
{
    for (auto &v : adj[u]) if (v != p)
    {
        d[v] = d[u] + a[v];
        DFS(v, u);
    }

    int k = 0;
    long long tmp = 0;

    FOR(mask, 1, MK(sz(facts[a[u]])) - 1)
    {
        int delta = __builtin_parity(mask) ? 1 : -1;
        int lcm = GetLCM(a[u], mask);

        tmp += delta * len[lcm];
        k += delta * cnt[lcm];
    }

    // if (u == 3) k = tmp = 0;
    cout << "debug: " << u << ' ' << k << ' ' << tmp << '\n';
    res += tmp - 1LL * k * (d[u] - a[u]);
    for (auto &x : divs[a[u]]) cnt[x]++, len[x] += d[u];
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

    Sieve();
    d[1] = a[1];
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