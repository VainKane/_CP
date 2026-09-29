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
#define name "E"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

#pragma GCC optimize("O3,Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,tune=native")

mt19937_64 rd(time(0));
ll Rand(ll l, ll r) { return l + rd() * 1LL * rd() % (r - l + 1); }

int const N = 509;
int const K = 22;
int const lim = 30 * 60000;

int n, k, t;

int a[N][6];
int d[N][N];
int l[6], r[6];

int id[N], resId[N];
pair<ll, ll> val, resVal;

vector<int> gr[K];
pair<ll, ll> grVal[K];
ll sum[K][6];

void Init()
{
    FOR(i, 1, k) id[i] = id[i + k] = i;
    FOR(i, 2 * k + 1, n) id[i] = Rand(1, k);

    shuffle(id + 1, id + n + 1, rd);
    FOR(i, 1, n) resId[i] = id[i];
}

pair<ll, ll> Eval(int id[])
{
    FOR(i, 1, k) gr[i].clear();
    FOR(i, 1, n) gr[id[i]].push_back(i);

    pair<ll, ll> res = {0, 0};
    FOR(i, 1, k)
    {
        grVal[i] = {0, 0};
        for (auto &z : gr[i]) for (auto &u : gr[i]) grVal[i].S += d[u][z];

        FOR(j, 1, t)
        {
            sum[i][j] = 0;
            for (auto &z : gr[i]) sum[i][j] += a[z][j];

            if (sum[i][j] < l[j]) grVal[i].F += l[j] - sum[i][j];
            if (sum[i][j] > r[j]) grVal[i].F += sum[i][j] - r[j];
        }

        res.F += grVal[i].F, res.S += grVal[i].S;
    }

    return res;
}

void Update(int idx, int i, int delta)
{
    if (delta == 1) id[i] = idx, gr[idx].push_back(i);
    else
    {
        vector<int> tmp;
        for (auto &j : gr[idx]) if (j != i) tmp.push_back(j);
        gr[idx] = tmp;
    }

    val.F -= grVal[idx].F, val.S -= grVal[idx].S;
    for (auto &j : gr[idx]) grVal[idx].S += delta * (d[i][j] + d[j][i]);

    grVal[idx].F = 0;
    FOR(j, 1, t)
    {
        sum[idx][j] += delta * a[i][j];
        if (sum[idx][j] < l[j]) grVal[idx].F += l[j] - sum[idx][j];
        if (sum[idx][j] > r[j]) grVal[idx].F += sum[idx][j] - r[j];
    }

    val.F += grVal[idx].F, val.S += grVal[idx].S;
}

bool SetOpt()
{
    bool opt = false;

    FOR(i, 1, n) if (sz(gr[id[i]]) > 2) FOR(j, 1, k)
    {
        auto cur = val;
        int curId = id[i];

        Update(curId, i, -1);
        Update(j, i, 1);

        if (val < cur) opt = true;
        else
        {
            Update(j, i, -1);
            Update(curId, i, 1);
        }
    }

    return opt;
}

bool SwapOpt()
{
    bool opt = false;

    FOR(u, 1, n) FOR(v, u + 1, n)
    // REP(haha, 1e4)
    {
        // int u = Rand(1, n - 1), v = Rand(u + 1, n);
        int idU = id[u], idV = id[v];
        auto cur = val;

        Update(idU, u, -1);
        Update(idV, v, -1);
        
        Update(idV, u, 1);
        Update(idU, v, 1);

        if (val < cur) opt = true;
        else
        {
            Update(idV, u, -1);
            Update(idU, v, -1);

            Update(idU, u, 1);
            Update(idV, v, 1);
        }
    }

    return opt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> k >> t;
    FOR(i, 1, n)
    {
        FOR(j, 1, t) cin >> a[i][j];
        FOR(j, 1, n) cin >> d[i][j];
    }

    FOR(i, 1, t) cin >> l[i];
    FOR(i, 1, t) cin >> r[i];

    Init();
    resVal = val = Eval(id);

    auto startTime = chrono::high_resolution_clock::now();
    while (chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count() <= lim)
    {
        cerr << fixed << "progress: " << (double)chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count() / lim * 100 << "% ";
        cerr << resVal.F << ' ' << resVal.S << '\n';

        bool opt = false;
        REP(haha, 1)
        {
            opt |= SetOpt();
            opt |= SwapOpt();
            opt |= SetOpt();
            opt |= SwapOpt();
        }

        if (mini(resVal, val)) FOR(i, 1, n) resId[i] = id[i];
        if (!opt)
        {
            FOR(i, 1, n / 20) swap(id[Rand(1, n)], id[Rand(1, n)]);
            val = Eval(id);
        }
    }

    assert(Eval(resId).F == 0);
    FOR(i, 1, k)
    {
        for (auto &j : gr[i]) cout << j << ' ';
        cout << '\n';
    }

    return 0;
}