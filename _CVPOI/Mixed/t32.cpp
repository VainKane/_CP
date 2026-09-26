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
int const lim = 60000 * 3;
int const oo = 1e9 + 9;

int m, n, k;
int a[N][N];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

vector<ii> pos, resPos;
ll val, resVal;

bool visited[N][N];

int id[N][N];
multiset<int> s[N];

bool Inside(int x, int y) { return x >= 1 && x <= m && y >= 1 && y <= n; }
int Dist(ii a, ii b) { return abs(a.F - b.F) + abs(a.S - b.S); }
bool cmp(ii x, ii y) { return a[x.F][x.S] > a[y.F][y.S]; }

void Build(int i)
{
    s[i].clear();
    REP(j, k) if (i != j) s[i].insert(Dist(pos[i], pos[j]));
}

void Init(bool haha = true)
{
    REP(i, n * m) s[i].clear();
    pos.clear();

    FOR(i, 1, m) FOR(j, 1, n) pos.push_back({i, j});
    sort(all(pos), cmp);

    REP(i, m * n)
    {
        int x = pos[i].F, y = pos[i].S;
        id[x][y] = i;
    }

    REP(i, k) Build(i);
}

ll Eval(vector<ii> &pos)
{
    ll res = 0;
    REP(i, k) res += 1LL * a[pos[i].F][pos[i].S] * *s[i].begin();
    return res;
}

bool SwapOpt(int x, int y, int u, int v)
{
    int i = id[x][y], j = id[u][v];

    swap(pos[i], pos[j]);
    swap(id[x][y], id[u][v]);

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

    resPos = vector<ii>(k, {0, 0});
    REP(i, k) resPos[i] = pos[i];

    auto startTime = chrono::high_resolution_clock::now();
    double per = 0;

    while (per < 100)
    {
        per = (double)chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count() / lim * 100;
        cerr << fixed << "Progress: " << per << "%: " << resVal << '\n';

        bool opt = false;
        REP(haha, 10)
        {
            int i = Rand(0, k - 1);
            int x = pos[i].F, y = pos[i].S;
            REP(dir, 4)
            {
                int dist = Rand(1, 20);

                int u = x + dx[dir] * dist;
                int v = y + dy[dir] * dist;

                if (!Inside(u, v) || id[u][v] < k) continue;
                if (SwapOpt(x, y, u, v))
                {
                    opt = true;
                    break;
                }
            }
        }

        REP(haha, 10)
        {
            int i = Rand(0, k - 1), j = Rand(k, n - 1);
            int x = pos[i].F, y = pos[i].S;
            int u = pos[j].F, v = pos[j].S;

            opt |= SwapOpt(x, y, u, v);
        }

        if (maxi(resVal, val)) REP(i, k) resPos[i] = pos[i];
        if (!opt)
        {
            REP(haha, k / 15)
            {
                int i = Rand(0, k - 1), j = Rand(k, m * n - 1);
                int x = pos[i].F, y = pos[i].S;
                int u = pos[i].F, v = pos[i].S;

                swap(pos[i], pos[j]);
                swap(id[x][y], id[u][v]);
            }
            val = Eval(pos);
        }
    }

    REP(i, k) cout << resPos[i].F << ' ' << resPos[i].S << '\n';

    return 0;
}