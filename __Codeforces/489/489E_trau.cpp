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

int const N = 36;
int const oo = 1e9;

int n, l;
int x[N], b[N];

double Cal(int &mask)
{
    vector<int> v;
    int haha = 0;

    for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
    {
        int i = __builtin_ctz(tmp & -tmp);
        haha += b[i];
        v.push_back(i);
    }
    
    double res = sqrt(abs(x[v[0]] - l));
    FOR(i, 1, sz(v) - 1) res += sqrt(abs(x[v[i]] - x[v[i - 1]] - l));
    return res / haha;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> l;
    REP(i, n) cin >> x[i] >> b[i];

    double mi = oo;
    int res = 0;

    REP(mask, MK(n)) if (BIT(n - 1, mask) && mini(mi, Cal(mask))) res = mask;
    // for (int tmp = res; tmp; tmp ^= tmp & -tmp) cout << __builtin_ctz(tmp & -tmp) + 1 << ' ';

    cout << mi;

    return 0;
}