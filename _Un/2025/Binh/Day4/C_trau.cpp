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

int const N = 1e3 + 5;

int m, n, k, q;
bool a[N][N];

bool Check(int x1, int y1, int x2, int y2)
{
    bool ok1 = true, ok2 = true;
    FOR(x, x1, x2)
    {
        bool ok = false;
        FOR(y, y1, y2) if (a[x][y])
        {
            ok = true;
            break;
        }

        if (!ok)
        {
            ok1 = false;
            break;
        }
    }

    FOR(y, y1, y2)
    {
        bool ok = false;
        FOR(x, x1, x2) if (a[x][y])
        {
            ok = true;
            break;
        }

        if (!ok)
        {
            ok2 = false;
            break;
        }
    }

    return ok1 | ok2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n >> k >> q;
    FOR(i, 1, k)
    {
        int x, y;
        cin >> x >> y;
        a[x][y] = true;
    }

    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << Check(x1, y1, x2, y2) << '\n';
    }

    return 0;
}