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
int const lim = 4 * 9200;

int n, m, b;
int w[N];

int id[N], resId[N];
pair<ll, int> val, resVal;

ll sum[N];

ll Pen(int i)
{
    if (i == 0) return 0;
    
    int x = 9 * (m + 1) / 10;
    if (sum[i] < x) return x - sum[i];
    if (sum[i] > m) return sum[i] - m;
    return 0;
}

pair<ll, int> Eval(int id[])
{
    pair<ll, int> res = {0, 0};

    FOR(i, 1, b) sum[i] = 0;
    FOR(i, 1, n) sum[id[i]] += w[i], res.S -= id[i] != 0;
    FOR(i, 1, b) res.F += Pen(i);

    return res;
}

void Set(int i, int idx)
{
    if (id[i] == idx) return;

    val.F -= Pen(id[i]);
    val.S -= !id[i] && idx;

    sum[id[i]] -= w[i];
    sum[idx] += w[i];
    id[i] = idx;

    val.F += Pen(idx);
    val.S += !idx && id[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    auto startTime = chrono::high_resolution_clock::now();

    cin >> n >> m >> b;
    FOR(i, 1, n) cin >> w[i];

    FOR(i, 1, n) resId[i] = id[i] = Rand(0, b);
    val = resVal = Eval(id);

    while (chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count() <= lim)
    {
        bool opt = false;
        FOR(i, 1, n) FOR(j, 1, b)
        {
            auto cur = val;
            int curId = id[i];

            Set(i, j);

            if (val < cur) opt = true;
            else Set(i, curId);
        }

        FOR(i, 1, n) FOR(j, i + 1, n)
        {
            int idI = id[i], idJ = id[j];
            auto cur = val;

            Set(i, idJ), Set(j, idI);
            
            if (val < cur) opt = true;
            else Set(i, idI), Set(j, idJ); 
        }

        if (mini(resVal, val)) FOR(i, 1, n) resId[i] = id[i];
        if (!opt)
        {
            FOR(i, 1, 15) swap(id[Rand(1, n)], id[Rand(1, n)]);
            val = Eval(id);
        }
    }

    assert(Eval(resId).F == 0);
    FOR(i, 1, n) cout << resId[i] << ' ';

    return 0;
}