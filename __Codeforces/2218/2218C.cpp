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

int n;
int a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;

        int x = 0;
        for (int i = 1; i <= 3 * n; i += 3) a[i] = ++x;

        x = 3 * n;
        for (int i = 3; i <= 3 * n; i += 3)
        {
            a[i] = x--;
            a[i - 1] = x--;
        }
       
        FOR(i, 1, 3 * n) cout << a[i] << ' ';
        cout << '\n';
    }

    return 0;
}