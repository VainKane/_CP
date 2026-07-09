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

int n;

ii a[N];
int preMin[N], preMax[N];
int sufMin[N], sufMax[N];

void Init()
{
    preMin[0] = sufMin[n + 1] = oo;
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
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i].F >> a[i].S;

    sort(a + 1, a + n + 1);
    Init();

    int res = 2 * oo;
    FOR(r, 1, n) FOR(l, 1, r) if (l != 1 || r != n)
    {
        int ma = max(preMax[l - 1], sufMax[r + 1]);
        int mi = min(preMin[l - 1], sufMin[r + 1]);
        mini(res, a[r].F - a[l].F + ma - mi);
    }

    cout << res;

    return 0;
}