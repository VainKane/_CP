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

int const N = 5e6 + 5;
int const MOD = 998244353;

int GCD(int a, int b)
{
    while (true)
    {
        if (a == 0 || b == 0 || a == b) return a | b;
        if (a > b) a %= b; else b %= a;
    }
}

int a, b;

int n;
int phi[N];

void Init()
{
    FOR(i, 1, b) phi[i] = i;
    FOR(i, 2, b) if (phi[i] == i) for (int j = i; j <= b; j += i) phi[j] -= phi[j] / i;
}

int Cal(int x)
{
    int res = x;
    for (int i = 2; i * i <= x; i++) if (x % i == 0)
    {
        while (x % i == 0) x /= i;
        res -= res / i;
    }

    if (x != 1) res -= res / x;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> a >> b;

    Init();

    ll pa = Cal(a);

    int res = 0;
    FOR(i, 1, b)
    {
        int d = GCD(a, i);
        res = (res + pa * phi[i] / phi[d] * d) % MOD;
    }

    cout << res;

    return 0;
}