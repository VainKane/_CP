#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1ll << (i))
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

int const N = 2e5 + 5;
int const BASE = 256;
int const NMOD = 2;
int const MODS[] = {(int)1e9 + 2277, (int)1e9 + 5277};

struct Hash
{
    int x[NMOD];

    Hash()
    {
        memset(x, 0, sizeof x);
    }

    bool operator < (Hash const other) const
    {
        REP(k, NMOD) if (x[k] != other.x[k]) return x[k] < other.x[k];
        return false;
    }

    bool operator == (Hash const other) const
    {
        REP(k, NMOD) if (x[k] == other.x[k]) return true;
        return false;
    }
};

string s1, s2;
int n, m;

int pw[NMOD][N];
int hs1[NMOD][N];
int hs2[NMOD][N];

void Init()
{
    n = sz(s1), m = sz(s2);
    s1 = " " + s1;
    s2 = " " + s2;

    REP(k, NMOD)
    {
        pw[k][0] = 1;
        FOR(i, 1, max(m, n)) pw[k][i] = 1ll * pw[k][i - 1] * BASE % MODS[k];
        FOR(i, 1, n) hs1[k][i] = (hs1[k][i - 1] + 1ll * s1[i] * pw[k][i - 1]) % MODS[k];
        FOR(i, 1, m) hs2[k][i] = (hs2[k][i - 1] + 1ll * s2[i] * pw[k][i - 1]) % MODS[k];
    }
}

Hash GetHash(int l, int r, int hs[NMOD][N])
{
    Hash res;

    REP(k, NMOD)
    {
        int tmp = hs[k][r] - hs[k][l - 1];
        if (tmp < 0) tmp += MODS[k];
        res.x[k] = 1ll * tmp * pw[k][max(m, n) - l] % MODS[k];
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s1 >> s2;

    Init();

    int res = 0;

    FOR(len, 1, min(m, n))
    {
        vector<Hash> v;
        FOR(i, 1, n - len + 1) v.push_back(GetHash(i, i + len - 1, hs1));
        sort(all(v));

        FOR(i, 1, m - len + 1) 
        {
            Hash hs = GetHash(i, i + len - 1, hs2);
            res += upper_bound(all(v), hs) - lower_bound(all(v), hs);
        }
    }

    cout << res;

    return 0;
}