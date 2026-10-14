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

int const N = 3e6 + 5;
int const LOG = 23;

int GCD(int a, int b)
{
    while (true)
    {
        if (a == b || b == 0 || a == b) return a | b;
        if (a > b) a %= b; else b %= a;
    }
}

int n;
int a[N];

void up[LOG][N];

void Init()
{
    FOR(i, 1, n) up[0][i] = a[i];
    FOR(j, 1, 31 - __builtin_clz(n)) FOR(i, 1, n - MK(j) + 1)
        up[j][i] = GCD(up[j - 1][i], up[j - 1][i + MK(j - 1)]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    Init();

    FOR(len, 1, n)
    {
    }

    return 0;
}