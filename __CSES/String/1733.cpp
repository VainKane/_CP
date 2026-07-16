#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)

int const N = 1e6 + 5;
int const BASE = 256;
int const NMOD = 2;
int const MODS[] = {(int)1e9 + 2277, (int)1e9 + 5277};

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

struct Hash
{
    int val[NMOD];

    Hash()
    {
        memset(val, 0, sizeof val);
    }

    bool operator != (Hash const other) const
    {
        REP(k, NMOD) if (val[k] == other.val[k]) return false;
        return true;
    }
};

int n;
string s;

int pw[NMOD][N]; 
int hs[NMOD][N];

void Init()
{
    n = s.size();
    s = " " + s;

    REP(k, NMOD)
    {
        pw[k][0] = 1;
        FOR(i, 1, n)
        {
            pw[k][i] = 1ll * pw[k][i - 1] * BASE % MODS[k];
            hs[k][i] = (hs[k][i - 1] + 1ll * s[i] * pw[k][i - 1]) % MODS[k];
        }
    }
}

Hash GetHash(int l, int r)
{
    Hash res;

    REP(k, NMOD)
    {
        int tmp = hs[k][r] - hs[k][l - 1];
        if (tmp < 0) tmp += MODS[k];

        res.val[k] = 1ll * tmp * pw[k][n - l + 1] % MODS[k];
    }

    return res;
}

bool Check(int len)
{
    for (int i = 1; i <= n; i += len) 
    {
        mini(len, n - i + 1);
        if (GetHash(1, len) != GetHash(i, i + len - 1)) return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;

    Init();
    FOR(len, 1, n) if (Check(len)) cout << len << ' ';

    return 0;
}