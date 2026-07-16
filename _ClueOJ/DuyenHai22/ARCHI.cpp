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

int const N = 109;
int const dx[] = {0, 1, 0, -1};
int const dy[] = {1, 0, -1, 0};

struct State
{
    int x, y;
    int du;
};

int n, m, q;

int x[N], y[N], u[N], v[N];
int xs[N], ys[N], xt[N], yt[N];

int a[8 * N][8 * N];
int d[8 * N][8 * N];

void Compress()
{
    vector<int> vals;

    FOR(i, 1, n)
    {
        vals.push_back(x[i]);
        vals.push_back(y[i]);
        vals.push_back(u[i]);
        vals.push_back(v[i]);
    }

    FOR(i, 1, q)
    {
        vals.push_back(xs[i]);
        vals.push_back(ys[i]);
        vals.push_back(xt[i]);
        vals.push_back(yt[i]);
    }

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    #define GetId(x) (lower_bound(all(vals), (x)) - vals.begin() + 1)

    FOR(i, 1, n)
    {
        x[i] = GetId(x[i]), y[i] = GetId(y[i]);
        u[i] = GetId(u[i]), v[i] = GetId(v[i]);
    }

    FOR(i, 1, q)
    {
        xs[i] = GetId(xs[i]), ys[i] = GetId(ys[i]);
        xt[i] = GetId(xt[i]), yt[i] = GetId(yt[i]);
    }
    
    m = sz(vals);
}

bool Inside(int x, int y)
{
    return  x >= 1 && x <= m &&
            y >= 1 && y <= m;
}

void BFS(int xs, int ys)
{
    memset(d, 0x3f, sizeof d);
    d[xs][ys] = 0;

    deque<State> dq;
    dq.push_front({xs, ys, d[xs][ys]});

    while (!dq.empty())
    {
        int x = dq.front().x;
        int y = dq.front().y;
        int du = dq.front().du;
        dq.pop_front();

        if (du > d[x][y]) continue;

        REP(i, 4)
        {
            int u = x + dx[i];
            int v = y + dy[i];
            bool w = a[u][v] != a[x][y] && a[u][v];
            
            if (Inside(u, v) && mini(d[u][v], d[x][y] + w))
            {
                if (w) dq.push_back({u, v, d[u][v]});
                else dq.push_front({u, v, d[u][v]});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> x[i] >> y[i] >> u[i] >> v[i];
    FOR(i, 1, q) cin >> xs[i] >> ys[i] >> xt[i] >> yt[i];

    Compress();

    FOR(i, 1, n)
    {
        FOR(p, x[i], u[i]) a[p][y[i]] = a[p][v[i]] = i;
        FOR(p, y[i], v[i]) a[x[i]][p] = a[u[i]][p] = i;
    }

    FOR(i, 1, q)
    {
        BFS(xs[i], ys[i]);
        cout << d[xt[i]][yt[i]] << '\n';
    }

    return 0;
}