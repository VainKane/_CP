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

int const N = 1e4 + 5;

int n;

bool Query(int i, int j)
{
    cout << "? " << i << ' ' << j << '\n' << flush;
    int res; cin >> res;
    if (res == -1) exit(0);
    return res;
}

void Answer(int res)
{
    cout << "! " << res << '\n' << flush;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n;

        bool ok = true;
        for (int i = 3; i <= 2 * n - 1; i += 2) if (Query(i, i + 1))
        {
            ok = false;
            Answer(i);
            break;
        }

        if (ok)
        {
            if (Query(1, 3) || Query(1, 4)) Answer(1);
            else Answer(2);
        }
    }

    return 0;
}