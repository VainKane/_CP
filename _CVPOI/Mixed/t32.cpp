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
#define name "t32"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

#pragma GCC optimize("O3,Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,tune=native")

mt19937_64 rd(time(0));
ll Rand(ll l, ll r) { return l + rd() * 1LL * rd() % (r - l + 1); }

int const N = 1009;
int const lim = 60000 * 1;
int const oo = 1e9 + 9;

int m, n, k;
int a[N][N];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

vector<ii> pos, resPos;
ll val, resVal;

bool mark[N][N];
bool visited[N][N];

int d[N][N];

bool Inside(int x, int y) { return x >= 1 && x <= m && y >= 1 && y <= n; }
int Dist(ii a, ii b) { return abs(a.F - b.F) + abs(a.S - b.S); }

bool cmp(ii x, ii y) { return a[x.F][x.S] > a[y.F][y.S]; }

void Init()
{
    memset(mark, false, sizeof mark);
    pos.clear();

    vector<ii> v;
    FOR(i, 1, m) FOR(j, 1, n) v.push_back({i, j});
    // shuffle(all(v), rd);
    sort(all(v), cmp);

    REP(i, k)
    {
        mark[v[i].F][v[i].S] = true;
        pos.push_back(v[i]);
    }
}

int BFS(int xs, int ys)
{
    queue<ii> q;
    q.push({xs, ys});

    d[xs][ys] = 0;
    visited[xs][ys] = true;
    vector<ii> v = {{xs, ys}};

    while (!q.empty())
    {
        int x = q.front().F, y = q.front().S;
        v.push_back({x, y});

        REP(i, 4)
        {
            int u = x + dx[i], v = y + dy[i];
            if (!Inside(u, v) || visited[u][v]) continue;

            if (mark[u][v]) return d[u][v];

            d[u][v] = d[x][y] + 1;
            visited[u][v] = true;
            q.push({u, v});
        }
    }

    for (auto &p : v) visited[p.F][p.S] = false;
    return 0;
}

ll Eval(vector<ii> &pos, bool haha = true)
{
    ll res = 0;
    if (haha) REP(i, k)
    {
        int dist = oo;
        REP(j, i) if (i != j) mini(dist, Dist(pos[i], pos[j]));
        res += 1LL * a[pos[i].F][pos[i].S] * dist;
    }
    else REP(i, k) res += 1LL * BFS(pos[i].F, pos[i].S) * a[pos[i].F][pos[i].S];

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> m >> m >> n >> k;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    Init();
    resVal = val = Eval(pos);
    resPos = pos;

    auto startTime = chrono::high_resolution_clock::now();
    double per = 0;

    while (per < 100)
    {
        per = (double)chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count() / lim * 100;
        assert(Eval(resPos) == resVal);
        cerr << fixed << "Progress: " << per << "%: " << resVal << '\n';

        bool opt = false;
        REP(i, k)
        {
            vector<ii> curPos = pos;
            ll curVal = val;

            REP(dir, 4)
            {
                int dist = Rand(1, 20);
                int x = pos[i].F + dx[dir] * dist;
                int y = pos[i].S + dy[dir] * dist;
                if (!Inside(x, y) || mark[x][y]) continue;

                vector<ii> tmp;
                REP(j, k)
                {
                    if (j == i) tmp.push_back({x, y});
                    else tmp.push_back(pos[j]);
                }

                ll tmpVal = Eval(tmp);
                if (maxi(val, tmpVal))
                {
                    mark[pos[i].F][pos[i].S] = false;
                    mark[x][y] = true;
                    pos = tmp, opt = true;
                }
            }
        }

        if (maxi(resVal, val)) resPos = pos;
        if (!opt)
        {
            Init();
            val = Eval(pos);
        }
    }

    REP(i, k) cout << resPos[i].F << ' ' << resPos[i].S << '\n';

    return 0;
}