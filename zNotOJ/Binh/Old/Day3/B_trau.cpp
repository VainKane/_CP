#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1 << (i))

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 409;
int const oo = N + 1;

int m, n;

int a[N][N];
int colMask[N];

int last[6];

long long res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m;
    FOR(i, 1, m)
    {
        string s; cin >> s;
        n = s.size();
        
        FOR(j, 1, n) a[i][j] = s[j - 1] - 'A';
    }

    FOR(l, 1, m) 
    {
        memset(colMask, 0, sizeof colMask);

        FOR(r, l, m) FORD(i, n, 1)
        {
            colMask[i] |= MK(a[r][i]);
            int mask = 0;

            FOR(j, i, n)
            {
                mask |= colMask[j];
                int k = __builtin_popcount(mask);

                res += k == 3;
                if (k > 3) break;
            }
        }
    }

    cout << res;

    return 0;
}