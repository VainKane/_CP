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

int const N = 36;
int const MOD = 998244353;
int const oo = 1e9 + 9;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int n, k;
int a[N];

int Cal(vector<int> &v)
{
    sort(all(v));

    int res = oo;
    REP(i, sz(v) - 1) mini(res, v[i + 1] - v[i]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    REP(i, n) cin >> a[i];

    int res = 0;
    REP(mask, MK(n)) if (__builtin_popcount(mask) == k)
    {
        vector<int> v;
        for (int tmp = mask; tmp; tmp ^= tmp & -tmp) v.push_back(a[__builtin_ctz(tmp)]);
        Add(res, Cal(v));
    }

    cout << res;

    return 0;
}