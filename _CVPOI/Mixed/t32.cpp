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

mt19937_64 rd(time(0));
ll Rand(ll l, ll r) { return l + rd() * 1LL * rd() % (r - l + 1); }

int const N = 1009;
int const lim = 14950;
int const oo = 1e9 + 9;

int m, n, k;
int a[N][N];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

vector<ii> pos;
ll val, res;

bool mark[N][N];
bool visited[N][N];

int Dist(ii a, ii b) { return abs(a.F - b.F) + abs(a.S - b.S); }

void Init()
{
    vector<ii> v;
    FOR(i, 1, m) FOR(j, 1, n) v.push_back({i, j});
    shuffle(all(v), rd);

    REP(i, k) pos.push_back(v[i]);
}

int BFS(int xs, int ys)
{
    queue<ii> q;
    q.push({xs, ys});

    visited[xs][ys] = true;
    vector<ii> v;

    while (!q.empty())
    {
        int x = q.front().F, y = q.front().S;
        v.push_back({x, y});

        REP(i, 4)
        {
            int u = x + dx[i], v = y + dy[i];
            if (visited[u][v]) continue;

            visited[u][v] = true;
            q.push({u, v});
        }
    }
}

ll Eval()
{
    ll res = 0;
    if (k < lim) REP(i, k)
    {
        int dist = oo;
        REP(j, i) if (i != j) mini(dist, Dist);
        res += 1LL * a[i][j] * dist;
    }
    else
    {
        REP(i, k) mark[pos[i].F][pos[i].S] = true;
        REP(i, k) mark[pos[i].F][pos[i].S] = false;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    auto startTime = chrono::high_resolution_clock::now();

    cin >> m >> m >> n >> k;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    Init();
    res = val = Eval();

    while (chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count() <= lim)
    {

    }

    return 0;
}