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
#define name "K"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

#pragma GCC optimize("O3,Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,tune=native")

mt19937_64 rd(time(0));
ll Rand(ll l, ll r) { return l + rd() * 1LL * rd() % (r - l + 1); }

int const N = 1e5 + 5;
int const lim = 40 * 60000;
ll const oo = 1e18 + 9;

int n;
int x[N], y[N];

int id[N], resId[N];
pair<ll, ll> val, resVal;
ll pre[N];

int Dist(int i, int j) { return abs(x[i] - x[j]) + abs(y[i] - y[j]); }

pair<ll, ll> Eval()
{
    pair<ll, ll> res = {0, 0};

    FOR(i, 2, n / 2) res.F += Dist(id[i], id[i - 1]);
    FOR(i, n / 2 + 2, n) res.S += Dist(id[i], id[i - 1]);

    return res;
}

bool cmp(int i, int j) { return x[i] + y[i] < x[j] + y[j]; }

void Init()
{
    FOR(i, 1, n) id[i] = i;
    sort(id + 1, id + n + 1, cmp);
    // shuffle(id + 1, id + n + 1, rd);

    FOR(i, 2, n) pre[i] = pre[i - 1] + Dist(id[i], id[i - 1]);

    pair<ll, int> tmp = {oo, 1};
    FOR(i, 1, n - n / 2 + 1) mini(tmp, {pre[i + n / 2 - 1] - pre[i], i});

    FOR(i, 1, n / 2) swap(id[i], id[tmp.S - 1 + i]);

    resVal = val = Eval();
    FOR(i, 1, n) resId[i] = id[i];
}

bool TwoOpt(ll &x, int OS = 0)
{
    bool opt = false;
    REP(haha, 1e3)
    {
        int i = Rand(2, n / 2 - 3), j = Rand(i + 2, n / 2);
        i += OS, j += OS;

        int delta = Dist(id[i - 1], id[j - 1]) + Dist(id[i], id[j]) - Dist(id[i - 1], id[i]) - Dist(id[j - 1], id[j]);
        if (delta < 0)
        {
            x += delta;
            reverse(id + i, id + j);
            opt = true;
        }
    }

    val = Eval();
    return opt;
}

bool CrossExchange()
{
    bool opt = false;
    REP(haha, 1e3)
    {
        int len = Rand(1, 20);
        int i = Rand(2, n / 2 - len), j = Rand(n / 2 + 2, n - len);

        ll delta = Dist(id[j], id[i - 1]) - Dist(id[i], id[i - 1]) + Dist(id[j + len - 1], id[i + len]) - Dist(id[i + len - 1], id[i + len]);
        FOR(k, 1, len - 1) delta += Dist(id[j + k - 1], id[j + k]) - Dist(id[i + k - 1], id[i + k]);
    
        if (delta < 0)
        {
            REP(k, len) swap(id[i + k], id[j + k]);
            val.F += delta;
            opt = true;
        }
    }

    val = Eval();
    return opt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> n;
    FOR(i, 1, n) cin >> x[i] >> y[i];

    Init();

    auto startTime = chrono::high_resolution_clock::now();
    while (chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count() <= lim)
    {
        auto tt = (double)chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count() * 100 / lim;
        cerr << fixed << "progress: " << tt << "%: " << resVal.F << ' '<< resVal.S << '\n';

        bool opt = false;
        REP(haha, 100)
        {
            opt |= TwoOpt(val.F);
            opt |= TwoOpt(val.S, n / 2);
            opt |= CrossExchange();
            opt |= TwoOpt(val.F);
            opt |= TwoOpt(val.S, n / 2);
        }

        if (mini(resVal, val)) FOR(i, 1, n) resId[i] = id[i];
        if (!opt)
        {
            REP(haha, n / 20)
            {
                int i = Rand(1, n / 2), j = Rand(n / 2 + 1, n);
                swap(id[i], id[j]);
            }

            REP(haha, n / 20)
            {
                int i = Rand(1, n / 2), j = Rand(1, n / 2);
                swap(id[i], id[j]);
            }
            
            val = Eval();
        }
    }

    FOR(i, 1, n / 2) cout << resId[i] << ' ';

    return 0;
}