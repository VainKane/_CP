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

struct Node
{
    int a, b, szA, szB, p;
};

struct Edge
{
    int u, v, a, b;

    bool operator == (Edge const other) const
    {
        return 1LL * a * other.b == 1LL * b * other.a;
    }

    bool operator < (Edge const other) const
    {
        return 1LL * a * other.b < 1LL * b * other.a;
    }
};

struct DSU
{
    vector<int> par;
    vector<int> sz;
    int n;

    vector<Node> st;
    int res = 1;

    void MakeSet()
    {
        FOR(i, 1, n)
        {
            par[i] = i;
            sz[i] = 1;
        }
    }

    DSU(int _n = 0)
    {
        n = _n;
        par.assign(n + 5, 0);
        sz.assign(n + 5, 0);

        MakeSet();
    }

    int Find(int v)
    {
        return par[v] == v ? v : Find(par[v]);
    }

    void Union(int a, int b, bool ok = true)
    {
        a = Find(a);
        b = Find(b);

        if (a == b) return;

        if (sz[a] < sz[b]) swap(a, b);
        
        if (ok) st.push_back({a, b, sz[a], sz[b], par[b]});
        maxi(res, sz[a] += sz[b]);
        par[b] = a;
    }

    void Roll()
    {
        while (!st.empty())
        {
            Node v = st.back();
            st.pop_back();

            par[v.b] = v.p;
            sz[v.a] = v.szA;
            sz[v.b] = v.szB;
        }        
    }
};

int const N = 707;
int const dx[] = {-1, 0, 1, 0};
int const dy[] = {0, 1, 0, -1}; 

int n;
int h[N][N], v[N][N];

vector<Edge> edges;
DSU dsu;

int GetId(int i, int j)
{
    return (i - 1) * n + j;
}

bool Inside(int x, int y)
{
    return  x >= 1 && x <= n &&
            y >= 1 && y <= n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) FOR(j, 1, n) cin >> h[i][j];
    FOR(i, 1, n) FOR(j, 1, n) cin >> v[i][j];

    dsu = DSU(n * n);

    FOR(i, 1, n) FOR(j, 1, n) REP(dir, 4)
    {
        int x = i + dx[dir];
        int y = j + dy[dir];

        if (!Inside(x, y)) continue;
        if (v[i][j] == v[x][y] && h[i][j] == h[x][y]) dsu.Union(GetId(i, j), GetId(x, y), 0);
        else 
        {
            int a = h[x][y] - h[i][j];
            int b = v[i][j] - v[x][y];
            if (1LL * a * b > 0) edges.push_back({GetId(i, j), GetId(x, y), abs(a), abs(b)});
        }
    }

    sort(all(edges));

    for (int i = 0, j; i < sz(edges); i = j)
    {
        for (j = i; j < sz(edges) && edges[j] == edges[i]; j++) dsu.Union(edges[j].u, edges[j].v);
        dsu.Roll();
    }

    cout << dsu.res;

    return 0;
}