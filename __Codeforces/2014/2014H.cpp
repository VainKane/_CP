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

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return rd() * 1LL * rd() % (r - l + 1); 
}

int const N = 11e5 + 5;
int const M = 1e6 + 5;

int n, q;

long long pre[N];
long long randVal[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    FOR(i, 1, 1e6) randVal[i] = Rand(1, 1e18);

    int t; cin >> t;
    while (t--)
    {
        cin >> n >> q;
        FOR(i, 1, n)
        {
            int x; cin >> x;
            pre[i] = pre[i - 1] ^ randVal[x];
        }

        while (q--)
        {
            int l, r;
            cin >> l >> r;
            cout << ((pre[r] ^ pre[l - 1]) == 0 ? "YES\n" : "NO\n");
        }
    }

    return 0;
}