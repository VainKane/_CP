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

int const N = 3e5 + 5;
long long const oo = 1e18;

int n;

int a[N], b[N];
bool mark[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n)
    {
        int t; cin >> t;

        if (t == 1) cin >> a[i] >> b[i], mark[i] ^= 1;
        else if (t == 2)
        {
            int id; cin >> id;
            mark[id] ^= 1;
        }
        else
        {
            int x; cin >> x;

            long long res = -oo;
            FOR(j, 1, i - 1) if (mark[j]) maxi(res, 1LL * x * a[j] + b[j]);
            
            if (res == -oo) cout << "EMPTY SET\n";
            else cout << res << '\n';
        }
    }

    return 0;
}