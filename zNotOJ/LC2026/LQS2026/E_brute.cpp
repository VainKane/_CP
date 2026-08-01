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
int const lim = 1 * 60000;

int n, k, t;

int a[N][6];
int d[N][N];
int l[6], r[6];

int id[N], resId[N];
int cnt[36];
vector<int> gr[N];

void Init()
{
    FOR(i, 1, k) id[i] = id[i + k] = i, cnt[i] = 2;
    FOR(i, 2 * k + 1, n) id[i] = Rand(1, k), cnt[id[i]]++;
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
        for (auto &z : gr[i]) for (auto &u : gr[i]) res.S += d[u][z];
        FOR(j, 1, t)
        {
            ll s = 0;
            for (auto &z : gr[i]) s += a[z][j];

            if (s < l[j]) res.F += l[j] - s;
            if (s > r[j]) res.F += s - r[j];
        }
    }

    return res;
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

    auto startTime = chrono::high_resolution_clock::now();
    while (chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count() <= lim)
    {
        cerr << fixed << "progress: " << (double)chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count() / lim * 100 << "% ";
        auto haha = Eval(resId);
        cerr << fixed << haha.F << ' ' << haha.S << '\n';

        bool opt = false;
        FOR(i, 1, n) if (cnt[id[i]] > 2) FOR(j, 1, k)
        {
            int curId = id[i];
            auto cur = Eval(id);

            id[i] = j;
            if (Eval(id) < cur)
            {
                cnt[curId]--, cnt[id[i]]++;
                opt = true;
            }
            else id[i] = curId;
        }

        FOR(u, 1, n) FOR(v, u + 1, n)
        {
            auto cur = Eval(id);

            swap(id[u], id[v]);
            if (Eval(id) < cur) opt = true;
            else swap(id[u], id[v]);
        }

        if (Eval(id) < Eval(resId)) FOR(i, 1, n) resId[i] = id[i];
        if (!opt) FOR(i, 1, n / 15) swap(id[Rand(1, n)], id[Rand(1, n)]);
    }

    assert(Eval(resId).F == 0);
    FOR(i, 1, k)
    {
        for (auto &j : gr[i]) cout << j << ' ';
        cout << '\n';
    }

    return 0;
}