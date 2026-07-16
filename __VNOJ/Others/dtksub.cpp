#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 5e4 + 5;
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

    bool operator == (Hash const other) const
    {
        REP(k, NMOD) if (x[k] != other.x[k]) return false;
        return true;
    }

    bool operator < (Hash const other) const
    {
        REP(k, NMOD) if (x[k] != other.x[k]) return x[k] < other.x[k];
        return false;
    }
};

int n, k;
char s[N];

int pw[NMOD][N];
int hs[NMOD][N];

void Init()
{
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

        res.x[k] = 1ll * tmp * pw[k][n - l + 1] % MODS[k];
    }

    return res;
}

int Cal(int len)
{
    map<Hash, int> mp;
    
    int res = 0;
    FOR(i, 1, n - len + 1) maxi(res, ++mp[GetHash(i, i + len - 1)]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n) cin >> s[i];

    Init();

    int l = 1;
    int r = n;
    int res = l;

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (Cal(mid) >= k)
        {
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << res;

    return 0;
}