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
int const lim = 3 * 60000;

int n;
int x[N], y[N];

int id[N], resId[N];
pair<ll, ll> val, resVal;

int Dist(int i, int j) { return abs(x[i] - x[j]) + abs(y[i] - y[j]); }

int Cost(int i, int idx)
{
    if (i == 1 || i == n / 2 + 1) return Dist(idx, id[i + 1]);
    if (i == n / 2 || i == n) return Dist(id[i - 1], idx);
    return Dist(id[i - 1], idx) + Dist(idx, id[i + 1]);
}

pair<ll, ll> Eval()
{
    pair<ll, ll> res = {0, 0};

    FOR(i, 2, n / 2) res.F += Dist(id[i], id[i - 1]);
    FOR(i, n / 2 + 2, n) res.S += Dist(id[i], id[i - 1]);

    return res;
}

bool cmp(int i, int j)
{
    if (x[i] == x[j]) return y[i] < y[j];
    return x[i] < x[j];
}

void Init()
{
    FOR(i, 1, n) id[i] = i;
    sort(id + 1, id + n + 1, cmp);
    shuffle(id + 1, id + n + 1, rd);

    resVal = val = Eval();
    FOR(i, 1, n) resId[i] = id[i];
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

        FOR(i, 2, n / 2 - 1) FOR(j, n / 2 + 2, n - 1)
        {
            int delta1 = Cost(i, id[j]) - Cost(i, id[i]);
            int delta2 = Cost(j, id[i]) - Cost(j, id[j]);

            if (delta1 < 0 || (delta1 == 0 && delta2 < 0))
            {
                swap(id[i], id[j]);
                val.F += delta1, val.S += delta2;
                opt = true;
            }
        }

        FOR(i, 1, n / 2) FOR(j, i + 2, n / 2)
        {
            int delta = Cost(i, id[j]) + Cost(j, id[i]) - Cost(i, id[i]) - Cost(j, id[j]);
            if (delta < 0)
            {
                swap(id[i], id[j]);
                val.F += delta;
                opt = true;
            }
        }

        // ll sum1 = 0, sum2 = 0;
        // int len = 0;

        // FOR(i, n / 2 + 2, n) sum2 += Dist(id[i], id[i - 1]);
        // FOR(i, 1, n / 2 - 1)
        // {
        //     int j = n - i;
        //     if (i > 1) sum1 += Dist(id[i], id[i - 1]);
        //     sum2 -= Dist(id[j], id[j + 1]);
        //     if (mini(val.F, sum1 + sum2 + Dist(id[i], id[n / 2 + 1]))) len = i;
        // }

        // if (len) FOR(i, 1, n / 2 - len) swap(id[len + i], id[n / 2 + i]);
        // val = Eval();

        if (mini(resVal, val)) FOR(i, 1, n) resId[i] = id[i];
        if (!opt)
        {
            REP(haha, n / 60)
            {
                int i = Rand(1, n / 2), j = Rand(n / 2 + 1, n);
                swap(id[i], id[j]);
            }

            val = Eval();
        }
    }

    FOR(i, 1, n / 2) cout << resId[i] << ' ';

    return 0;
}