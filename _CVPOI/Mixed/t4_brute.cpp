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
int const M = 1e6 + 5;
int const MOD = 1e9 + 7;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int n;
int a[N], pre[N];
int val[M];

void Init()
{
    int pw = 1;
    REP(i, 20)
    {
        for (int j = pw; j <= 1e6; j += pw) val[j] = pw;
        pw <<= 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i], pre[i] = pre[i - 1] + a[i];

    Init(); 

    int res = 0;
    FOR(i, 1, n) REP(j, i) Add(res, val[pre[i] - pre[j]]);
    cout << res;

    return 0;
}