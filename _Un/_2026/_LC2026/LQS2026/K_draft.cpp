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
int const lim = 1 * 60000;
ll const oo = 1e18;

struct FenwickTree
{
    vector<ll> bit;
    int n;

    FenwickTree(int _n = 0)
    {
        n = _n;
        bit.assign(n + 5, 0);
    }

    void Reset() { bit.assign(n + 5, 0); }

    void Update(int idx, int val) { for (; idx <= n; idx += idx & -idx) bit[idx] += val; }

    ll Get(int idx)
    {
        ll res = 0;
        for (; idx; idx ^= idx & -idx) res += bit[idx];
        return res;
    }

    ll Get(int l, int r) { return Get(r) - Get(l - 1); }
};

int n;
int x[N], y[N];

int nxt[N], resNxt[N];
int pre[N], resPre[N];

int pref[N];

int id[N];

pair<ll, ll> val, resVal;
FenwickTree bit;

ll Sum(int l, int r)
{
    if (l > r) return 0;
    return pref[r] - pref[l - 1];
}

int GetId(int i)
{
    if (i == 1 || i == n / 2 + 1) return pre[i + 1];
    return nxt[i - 1];
}

int Dist(int i, int j)
{
    if (!i || !j) return 0;
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

int Cost(int i, int idx) { return Dist(pre[i], idx) + Dist(nxt[i], idx); }

void SetId(int i, int idx)
{
    // nxt[i - 1] = pre[i + 1] = idx;
    int j = GetId(i);
    if (i != 1 && i != n / 2 + 1)
    {
        // bit.Update(i, Dist(idx, pre[i]) -Dist(j, pre[i]));
        nxt[i - 1] = idx;
    }

    if (i != n / 2 && i != n)
    {
        // bit.Update(i + 1, Dist(idx, nxt[i]) - Dist(j, nxt[i]));
        pre[i + 1] = idx;
    }
}

pair<ll, ll> Eval()
{
    pair<ll, ll> res = {0, 0};
    // bit.Reset();

    FOR(i, 2, n / 2)
    {
        int idx = GetId(i);
        res.F += Dist(pre[i], idx);
        // bit.Update(i, Dist(pre[i], idx));
    }

    FOR(i, n / 2 + 2, n)
    {
        int idx = GetId(i);
        res.S += Dist(pre[i], GetId(i));
        // bit.Update(i, Dist(pre[i], idx));
    }

    return res;
}

void SetPreNxt() { FOR(i, 1, n) resPre[i] = pre[i], resNxt[i] = nxt[i]; }
void SetPref() { FOR(i, 2, n) pref[i] = pref[i - 1] + Dist(GetId(i), GetId(i - 1)); }

bool cmp(int i, int j)
{
    if (x[i] == x[j]) return y[i] < y[j];
    return x[i] < x[j];
}

void Init()
{
    FOR(i, 1, n) id[i] = i;
    sort(id + 1, id + n + 1, cmp);
    // shuffle(id + 1, id + n + 1, rd);

    FOR(i, 2, n / 2) nxt[i - 1] = id[i], pre[i] = id[i - 1];
    FOR(i, n / 2 + 2, n) nxt[i - 1] = id[i], pre[i] = id[i - 1];

    resVal = val = Eval();
    SetPreNxt();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> n;
    FOR(i, 1, n) cin >> x[i] >> y[i];

    bit = FenwickTree(n);
    Init();

    auto startTime = chrono::high_resolution_clock::now();
    while (chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count() <= lim)
    {
        auto tt = (double)chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count() * 100 / lim;
        cerr << fixed << "progress: " << tt << "%: " << resVal.F << ' '<< resVal.S << '\n';

        bool opt = false;

        // shuffle(id + 1, id + n / 2 + 1, rd);
        // shuffle(id + n / 2 + 1, id + n + 1, rd);

        FOR(i, 1, n / 2) FOR(j, n / 2 + 1, n)
        {
            // int i = id[idx], j = id[n / 2 + idx];

            int idI = GetId(i), idJ = GetId(j);

            int delta1 = Cost(i, idJ) - Cost(i, idI);
            int delta2 = Cost(j, idI) - Cost(j, idJ);

            // FOR(k, 2, n / 2 - 1) assert(pre[k + 1] == nxt[k - 1]);
            // FOR(k, n / 2 + 2, n - 2) assert(pre[k + 1] == nxt[k - 1]);

            if (delta1 < 0 || (delta1 == 0 && delta2 < 0))
            {
                // auto cur = val;

                val.F += delta1, val.S += delta2;
                SetId(i, idJ), SetId(j, idI);
                opt = true;

                // assert(val == Eval());
                // if (cur < Eval())
                // {
                //     cerr << cur.F << ' ' << cur.S << '\n';
                //     cerr << Eval().F << ' ' << Eval().S << '\n';
                //     return 0;
                // }
                // // cerr << "passed\n";
                // assert(cur > Eval());
            }
        }

        // FOR(i, 1, n / 2) FOR(j, i + 2, n / 2)
        // {
        //     int idI = GetId(i), idJ = GetId(j);

        //     int delta = Cost(i, idJ) + Cost(j, idI) - Cost(i, idI) - Cost(j, idJ);
        //     if (delta < 0)
        //     {
        //         val.F += delta;
        //         SetId(i, idJ), SetId(j, idI);
        //         opt = true;
        //     }
        // }

        // assert(bit.Get(2, n / 2) == val.F);
        // assert(bit.Get(n / 2 + 2, n) == val.S);

        // SetPref();

        // int idx = 0;
        // FOR(len, 1, n / 2 - 2)
        // {
        //     int k = n / 2 - len;
        //     int d1 = Sum(2, len) + Dist(GetId(len), GetId(n / 2 + 1)) + Sum(n / 2 + 2, n / 2 + k);
        //     int d2 = Sum(len + 2, n / 2) + Dist(GetId(n / 2), GetId(n / 2 + k + 1)) + Sum(n / 2 + k + 2, n);

        //     if (mini(val, {d1, d2})) idx = len;
        // }

        // if (idx)
        // {
        //     int id1 = GetId(n / 2), id2 = GetId(n / 2 + 1);
        //     nxt[idx] = id2;
        //     pre[n - idx] = id1;

        //     // val = Eval();
        //     opt = true;
        // }

        // FORD(len, n / 2 - 1, 1) FOR(i, 1, n / 2 - len + 1) FOR(j, n / 2 + 1, n - k + 1)
        // {
        //     int idI = GetId(i), idJ = GetId(j);
        //     if (mini(val.F, Sum(i + 1, i + len - 1) + Dist(idI, idJ) + Sum(j + 1, j + k - 1)))
        //     {
        //         ll d1 = Sum(2, i - 1) + Dist(GetId(i - 1), GetId(i + len)) + Sum(i + len + 1, n / 2);
        //         ll d2 = Sum(n / 2 + 2, j - 1) + Dist(GetId(j - 1), GetId(j + k)) + Sum(j + k + 2, n);
        //         val.S = d1 + d2;

        //         int idJ = GetId(j);
        //         if (i != 1) nxt[i - 1] = idJ;

        //         idx = j;
        //         opt = true;
        //     }
        // }

        val = Eval();
        if (mini(resVal, val)) SetPreNxt();
        if (!opt)
        {
            REP(haha, n / 20)
            {
                int i = Rand(1, n / 2), j = Rand(n / 2 + 1, n);
                int idI = GetId(i), idJ = GetId(j);
                SetId(i, idJ), SetId(j, idI);
            }

            val = Eval();
        }
    }

    FOR(i, 1, n) cout << GetId(i) << ' ';

    return 0;
}