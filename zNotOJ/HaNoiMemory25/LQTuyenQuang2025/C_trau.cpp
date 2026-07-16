#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1ll << (i))

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 15;
int const oo = 1e9 + 1;

int m, n;
bool a[N][N];
bool b[N][N];

bool Check()
{
    REP(i, m)
    {
        int last = 0;
        FOR(j, 1, n - 1) if (b[i][j] != b[i][j - 1])
        {
            if (j - last >= 3) return false;
            last = j;
        }
        if (n - last >= 3) return false;
    }

    REP(j, n)
    {
        int last = 0;
        FOR(i, 1, m - 1) if (b[i][j] != b[i - 1][j])
        {
            if (i - last >= 3) return false;
            last = i;
        }
        if (m - last >= 3) return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> m >> n;
        REP(i, m) REP(j, n)
        {
            char ch; cin >> ch;
            a[i][j] = ch - '0';
        }

        int res = oo;

        REP(mask1, MK(m)) REP(mask2, MK(n))
        {
            REP(i, m) REP(j, n) b[i][j] = a[i][j] ^ BIT(i, mask1) ^ BIT(j, mask2);
            if (Check()) mini(res, __builtin_popcount(mask1) + __builtin_popcount(mask2));
        }

        if (res == oo) cout << "-1\n";
        else cout << res << '\n';
    }

    return 0;
}