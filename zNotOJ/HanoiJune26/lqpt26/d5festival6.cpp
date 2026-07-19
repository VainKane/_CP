#ifndef LOCALONLY
#include "festivallib.h"
#endif // LOCALONLY

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

int const N = 209;

int n, s;

vector<int> adj[N], revAdj[N];
int deg[N], h[N];
bool mark[N];

int cnt[N];

void DFS(int u)
{
    for (auto &v : adj[u])
    {
        h[v] = h[u] + 1;
        DFS(v);
    }
}

vector<int> solveGenius(int _n, int _s, const vector<int> &_a, const vector<int> &_b)
{
    n = _n, s = _s;

    REP(u, n) adj[u].clear(), revAdj[u].clear();
    memset(mark, 0, sizeof mark);
    memset(deg, 0, sizeof deg);
    memset(h, 0, sizeof h);

    REP(i, sz(_a))
    {
        adj[_a[i]].push_back(_b[i]);
        revAdj[_b[i]].push_back(_a[i]);
        deg[_b[i]]++;
    }

    REP(u, n) if (!sz(adj[u])) DFS(u);

    priority_queue<ii> pq;
    REP(u, n) if (!deg[u] && sz(adj[u])) pq.push({h[u], u});

    vector<int> res(n, 0);
    int timer = 0;

    while (!pq.empty())
    {
        vector<int> nodes;
        REP(haha, s) if (!pq.empty())
        {
            int u = pq.top().S; pq.pop();
            res[u] = timer++;
            for (auto &v : adj[u]) if (!mark[v] && !--deg[v]) nodes.push_back(v), mark[v] = true;
        }

        for (auto &u : nodes) pq.push({h[u], u});
    }

    REP(i, n) res[i] /= s;
    return res;
}

bool solveCitizen(const vector<int> &a, const vector<vector<int>> &h)
{
    n = sz(a) + 1;
    int day = sz(h);

    for (auto &x : a) cnt[x]++;
    for (auto &v : h) for (auto &x : v) cnt[x]--;

    FOR(i, 1, n) if (cnt[i])
    {
        if (cnt[i] == 1) return true;
        return day == n || day == n / cnt[i] + cnt[i] - 1;
    }

    return true;
}

#ifdef LOCALONLY
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    return 0;
}
#endif // LOCALONLY