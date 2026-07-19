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

int const N = 1e5 + 5;
int const MOD = 1e9 + 7;

int n;

pair<int, long long> pw[N];

pair<int, long long> Add(pair<int, long long> a, pair<int, long long> b)
{
    pair<int, long long> res = {a.F + b.F, a.S + b.S};
    if (res.F >= MOD)
    {
        res.F -= MOD;
        res.S++;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    pw[0] = {1, 0};
    FOR(i, 1, n) pw[i] = Add(pw[i - 1], pw[i - 1]);

    cout << pw[n].F << ' ' << pw[n].S;

    return 0;
}