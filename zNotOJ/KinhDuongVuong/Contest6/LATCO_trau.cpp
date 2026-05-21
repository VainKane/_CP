#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define MK(i) (1ll << (i))

template <class t> mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 102;

int n, m;
bool s1[N], s2[N];
bool tmp[N];
bool b[N];

bool isEqual()
{
    REP(p, n) 
    {
        bool ok = true;
        REP(i, n) if (tmp[i] != s2[(p + i) % n]) 
        {
            ok = false;
            break;
        }

        if (ok) return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    REP(i, n) 
    {
        char x; cin >> x;
        s1[i] = x - '0';
    }

    REP(i, n) 
    {
        char x; cin >> x;
        s2[i] = s2[i + n] = x - '0';
    }

    int res = n;

    REP(mask, MK(n))
    {
        memset(b, 0, 4 * (n + 1));
        for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
        {
            int i = __builtin_ctz(tmp & -tmp);
            REP(j, m) b[(i + j) % n] ^= 1;
        }

        REP(i, n) tmp[i] = s1[i] ^ b[i];
        if (isEqual()) 
        {
            mini(res, __builtin_popcount(mask));
            continue;
            // cout << mask << ' ' << res << '\n';
        }
    }

    // if (res == n + 5) res = 0;
    cout << res;

    return 0;
}