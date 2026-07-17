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

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1e6 + 5;

int n;
int cntDiv[N];
long long cntGCD[N];

long long C2(int x)
{
    return 1LL * x * (x - 1) / 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n)
    {
        int x; cin >> x;
        cntDiv[x]++;
    }

    FOR(i, 1, 1e6) for (int j = 2 * i; j <= 1e6; j += i) cntDiv[i] += cntDiv[j];
    FORD(i, 1e6, 1)
    {
        cntGCD[i] = C2(cntDiv[i]);
        for (int j = 2 * i; j <= 1e6; j += i) cntGCD[i] -= cntGCD[j];
    }

    cout << cntGCD[1];

    return 0;
}