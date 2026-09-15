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

int const N = 2e5 + 5;
int const LOG = 20;

int n, m;
int x[N], y[N];
int d1[N], d2[N];

int lastX[N], lastY[N];
int lastD1[N], lastD2[N];

int preX[N], preY[N];
int preD1[N], preD2[N];

int up[N][LOG];

void Compress(int a[])
{
    vector<int> vals;

    FOR(i, 1, n) vals.push_back(a[i]);
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n) a[i] = lower_bound(all(vals), a[i]) - vals.begin() + 1;
}

void Init()
{
    FOR(i, 1, n) up[i][0] = max({preX[i], preY[i], preD1[i], preD2[i]});
    FOR(j, 1, 31 - __builtin_clz(n)) FOR(i, 1, n - MK(j) + 1)
        up[i][j] = max(up[i][j - 1], up[i + MK(j - 1)][j - 1]);
}

int Get(int l, int r)
{
    int k = 31 - __builtin_clz(r - l + 1);
    return max(up[l][k], up[r - MK(k) + 1][k]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, n) cin >> x[i] >> y[i];

    FOR(i, 1, n) d1[i] = x[i] + y[i], d2[i] = x[i] - y[i];
    Compress(x), Compress(y);
    Compress(d1), Compress(d2);

    FOR(i, 1, n)
    {
        preX[i] = lastX[x[i]], preY[i] = lastY[y[i]];
        preD1[i] = lastD1[d1[i]], preD2[i] = lastD2[d2[i]];

        lastX[x[i]] = lastY[y[i]] = lastD1[d1[i]] = lastD2[d2[i]] = i;
    }

    Init();

    int q; cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << (Get(l, r) < l ? "Yes\n" : "No\n");
    }

    return 0;
}