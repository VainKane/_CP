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

int const N = 255;

struct Edge
{
    int u, v, cu, cv;

    Edge(int _u = 0, int _v = 0, int _cu = 0, int _cv = 0) { u = _u, v = _v, cu = _cu, cv = _cv; }
    bool operator < (Edge const other) const { return make_pair(cu, cv) < make_pair(other.cu, other.cv); }
    bool operator == (Edge const other) const
    {
        if (cu == other.cu && cv == other.cv) return true;
        if (cu == other.cv && cv == other.cu) return true;
        return false;
    }
};

struct Data
{
    int u, v, parV, szV, valV;

    Data(int _u = 0, int _v = 0, int _parV = 0, int _szV = 0, int _valV = 0) { u = _u, v = _v, parV = _parV, szV = _szV, valV = _valV; }
};

struct DSU
{
    vector<int> par, sz;
    vector<int> val;
    vector<Data> st;
    int n, res;

    DSU(int _n = 0)
    {
        n = _n;
        par = sz = val = vector<int>(n + 5, 0);
    }

    void MakeSet(int a[])
    {
        res = 0;
        FOR(i, 1, n)
        {
            par[i] = i, sz[i] = 1;
            val[i] = a[i];
        }
    }

    int Find(int v) { return par[v] == v ? v : Find(par[v]); }

    void Union(int u, int v)
    {
        u = Find(u), v = Find(v);
        if (u == v) return;

        if (sz[u] < sz[v]) swap(u, v);
        st.push_back({u, v, par[v], sz[v], val[v]});

        maxi(res, val[u] += val[v]);
        sz[u] += sz[v];
        par[v] = u;
    }

    void Roll()
    {
        res = 0;
        while (!st.empty())
        {
            auto s = st.back();
            st.pop_back();

            val[s.u] -= s.valV;
            sz[s.u] -= s.szV;
            par[s.v] = s.parV;
        }
    }
};

int n;
int c[N][N];

int id[N][N];
int val[N * N];
int cc = 0;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

DSU dsu;

void BFS(int xs, int ys)
{
    queue<ii> q;
    q.push({xs, ys});

    id[xs][ys] = ++cc;

    while (!q.empty())
    {
        int x = q.front().F;
        int y = q.front().S;
        q.pop();

        val[cc]++;

        REP(i, 4)
        {
            int u = x + dx[i];
            int v = y + dy[i];

            if (c[u][v] == c[x][y] && !id[u][v])
            {
                id[u][v] = cc;
                q.push({u, v});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    memset(c, -1, sizeof c);

    cin >> n;
    FOR(i, 1, n) FOR(j, 1, n) cin >> c[i][j];

    FOR(i, 1, n) FOR(j, 1, n) if (!id[i][j]) BFS(i, j);

    vector<Edge> e;
    FOR(i, 1, n) FOR(j, 1, n) REP(dir, 4)
    {
        int x = i + dx[dir];
        int y = j + dy[dir];

        if (c[x][y] != -1 && c[x][y] != c[i][j]) e.push_back({id[i][j], id[x][y], c[i][j], c[x][y]});
    }

    sort(all(e));

    dsu = DSU(cc);
    dsu.MakeSet(val);

    int res = 0;
    for (int i = 0; i < sz(e);)
    {
        int j;
        for (j = i; j < sz(e) && e[i] == e[j]; j++) dsu.Union(e[j].u, e[j].v);

        maxi(res, dsu.res);
        dsu.Roll();
        i = j;
    }

    cout << *max_element(val + 1, val + cc + 1) << '\n' << res;

    return 0;
}