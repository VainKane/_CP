#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define MK(i) (1ll << (i))

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 102;

int n, m;
bool s1[N], s2[N];
bool b[N];

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
        s2[i] = x - '0';
    }

    int res = n;

    REP(p, n) REP(mask, MK(m - 1))
    {
        memset(b, 0, sizeof b);
        int cnt = __builtin_popcount(mask);

        for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
        {
            int i = __builtin_ctz(tmp & -tmp);
            REP(j, m) b[(i + j) % n] ^= 1;
        }

        FOR(i, m - 1, n - 1)
        {
            if ((s1[i] ^ b[i]) != s2[(p + i) % n])
            {
                REP(j, m) b[(i + j) % n] ^= 1;
                cnt++;
            }
        }

        bool ok = true;
        REP(i, min(n, m - 1)) if ((s1[i] ^ b[i]) != s2[(p + i) % n]) 
        {
            ok = false;
            break;
        }
        
        if (ok) mini(res, cnt);
    }

    cout << res;

    return 0;
}