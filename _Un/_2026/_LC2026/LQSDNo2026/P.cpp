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

int const N = 1e5 + 5;
int const BK = 314;

int n;
int a[N];

int pre[N], suf[N];

int f[BK + 5][N];
int mx[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    FOR(i, 1, n) pre[i] = pre[i - 1] + a[i];
    FORD(i, n, 1) suf[i] = pre[i + 1] + a[i];

    memset(mx, -0x3f, sizeof mx);
    FOR(s, 0, BK) FOR(i, 1, n)
    {
        if (s) f[s][i] = f[s - 1][i];
        if (pre[i] - s >= 0) maxi(f[s][i], mx[pre[i] - s] + 1);
        maxi(mx[s], f[s][i]);
    }

    return 0;
}