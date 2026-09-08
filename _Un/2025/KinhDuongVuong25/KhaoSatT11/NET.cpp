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
#define name "NET"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1e6 + 5;

int n;
pair<int, int> edges[N];
int deg[N];

namespace Sub1
{
    vector<int> adj[N];
    vector<int> topo;
    int inDeg[N];
    int f[N];

    bool CheckSub()
    {
        return n <= 20;
    }

    void BFS()
    {
        queue<int> q;
        FOR(u, 1, n) if (!inDeg[u]) q.push(u);

        while (!q.empty())
        {
            int u = q.front(); q.pop();
            topo.push_back(u);
            for (auto &v : adj[u]) if (!--inDeg[v]) q.push(v);
        }
    }

    int Cal()
    {
       int res = 0;
       BFS();

       for (auto &u : topo)
       {
           res += f[u] - 1;
           for (auto &v : adj[u]) f[v] += f[u];
       }

       return res;
    }

    void Solve()
    {
        int res = 0;

        REP(mask, MK(n - 1))
        {
            FOR(u, 1, n)
            {
                adj[u].clear();
                f[u] = 1;
            }
            topo.clear();

            REP(i, n - 1)
            {
                int u = edges[i].F;
                int v = edges[i].S;

                if (BIT(i, mask))
                {
                    adj[u].push_back(v);
                    inDeg[v]++;
                }
                else
                {
                    adj[v].push_back(u);
                    inDeg[u]++;
                }
            }

            maxi(res, Cal());
        }

        cout << res;
    }
}

namespace Sub4
{
    bool CheckSub()
    {
        int ok = false;
        FOR(u, 1, n) if (deg[u] > 1)
        {
            if (ok) return false;
            ok = true;
        }
        return true;
    }

    void Solve()
    {
        long long res = 0;
        FOR(i, 1, n)
        {
            int j = n - i;
            maxi(res, 1LL * i * j + j - 1);
        }
        cout << res;
    }
}
int main()
{
    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    REP(i, n - 1)
    {
        int u, v;
        cin >> u >> v;
        deg[u]++; deg[v]++;
        edges[i] = {u, v};
    }

    if (Sub1::CheckSub()) return Sub1::Solve(), 0;
    if (Sub4::CheckSub()) return Sub4::Solve(), 0;

    return 0;
}