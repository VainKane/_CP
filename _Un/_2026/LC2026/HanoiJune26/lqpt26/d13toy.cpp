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

int const N = 5e5 + 5;
int const oo = 1e9 + 9;
int const LOG = 20;

int n;

ii a[N];
int preMin[N], preMax[N];
int sufMin[N], sufMax[N];

int up2[N][LOG], up3[N][LOG];
int up4[N][LOG];

int la[N], ga[N];
int li[N], gi[N];

void Init()
{
    preMin[0] = sufMin[n + 1] = oo;
    preMax[0] = sufMax[n + 1] = -1;

    FOR(i, 1, n)
    {
        preMin[i] = min(preMin[i - 1], a[i].S);
        preMax[i] = max(preMax[i - 1], a[i].S);
    }

    FORD(i, n, 1)
    {
        sufMin[i] = min(sufMin[i + 1], a[i].S);
        sufMax[i] = max(sufMax[i + 1], a[i].S);
    }

    FOR(i, 1, n)
    {
        up2[i][0] = -a[i + 1].F -preMin[i];
        up3[i][0] = preMax[i] - a[i + 1].F;
        up4[i][0] = preMax[i] - preMin[i] - a[i + 1].F;
    }
}

void Build(int up[][LOG])
{
    FOR(j, 1, 31 - __builtin_clz(n)) FOR(i, 1, n - MK(j) + 1)
        up[i][j] = min(up[i][j - 1], up[i + MK(j - 1)][j - 1]);
}

int Get(int l, int r, int up[][LOG])
{
    if (l < 1 || r > n || l > r) return 2 * oo;

    int k = 31 - __builtin_clz(r - l + 1);
    return min(up[l][k], up[r - MK(k) + 1][k]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i].F >> a[i].S;

    sort(a + 1, a + n + 1);
    Init();
    Build(up2), Build(up3), Build(up4);

    int la = 0, ra = 0;
    int li = 0, ri = 0;

    ll res = 1LL * a[n].F + Get(1, n - 1, up4);
    FORD(i, n, 1)
    {
        while (la < n && preMax[la] < sufMax[i + 1]) la++;
        while (ra < n && preMax[ra + 1] <= sufMax[i + 1]) ra++;

        while (li < n && preMin[li] > sufMin[i + 1]) li++;
        while (ri < n && preMin[ri + 1] >= sufMin[i + 1]) ri++;

        int l, r;
        if (i < n)
        {
            r = min({ra, ri, i - 1});
            mini(res, 1LL * a[i].F - a[r + 1].F + sufMax[i + 1] - sufMin[i + 1]);

            r = min(ra, i - 1);
            mini(res, 1LL * a[i].F + sufMax[i + 1] + Get(li, r, up2));

            r = min(ri, i - 1);
            mini(res, 1LL * a[i].F - sufMin[i + 1] + Get(la, r, up3));
        }

        if (i > 1)
        {
            l = max(la, li);
            mini(res, 1LL * a[i].F + Get(l, i - 1, up4));
        }
    }

    cout << res;

    return 0;
}