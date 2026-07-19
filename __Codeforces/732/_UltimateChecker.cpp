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
#define name "732F"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

mt19937_64 rd(time(0));
int const ntest = 1e4;

int const N = 4e5 + 5;

int n, m;

vector<int> adj[N];
bool visited[N];

int f[N];

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int lim = 5000;

    n = Rand(2, lim);
    m = Rand(n - 1, lim);

    int a[n + 1];
    FOR(i, 1, n) a[i] = i;
    random_shuffle(a + 1, a + n + 1);

    set<pair<int, int>> e;
    vector<pair<int, int>> edges;

    FOR(i, 2, n) 
    {
        int v = a[Rand(1, i - 1)];
        e.insert({a[i], v});
        e.insert({v, a[i]});

        edges.push_back({a[i], v});
    }

    FOR(i, 1, m - n + 1) 
    {
        int u = Rand(1, n);
        int v = Rand(1, n);

        if (u == v) continue;
        if (e.count({u, v})) continue;

        edges.push_back({u, v});

        e.insert({u, v});
        e.insert({v, u});
    }

    m = sz(edges);
    cout << n << ' ' << m << '\n';
    for (auto &p : edges) cout << p.F << ' ' << p.S << '\n';
}

void DFS(int u)
{
    f[u] = visited[u] = 1;

    for (auto &v : adj[u]) if (!visited[v])
    {
        DFS(v);
        f[u] += f[v];
    }
}

void Check(int &idTest)
{
    ifstream cin(name".out");

    int res; cin >> res;
    FOR(u, 1, n) adj[u].clear();
    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int mi = 1e9;

    FOR(u, 1, n)
    {
        memset(f, 0, (n + 1) * 4);
        memset(visited, 0, n + 1);

        DFS(u);
        mini(mi, f[u]);
    }

    if (mi != res) 
    {
        cout << "Got trouble on test " << idTest << ":\n";
        cout << "Your ans is not correct, the real value of given ans is: " << mi << '\n';
        exit(0);
    }
}

int main()
{
    FOR(i, 1, ntest)
    {
        GenTest();
        system(name".exe <"name".inp> "name".out");

        Check(i);
        cout << "Good boy, the ans is correct (Test " << i << ")\n";
    }

    return 0;
}