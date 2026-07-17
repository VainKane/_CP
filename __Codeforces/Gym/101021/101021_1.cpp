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

bool Query(int x)
{
    cout << x << '\n' << flush;
    string s; cin >> s;
    return sz(s) == 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int l = 1;
    int r = 1e6;
    int res = r;

    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (Query(mid))
        {
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << "! " << res << flush;

    return 0;
}