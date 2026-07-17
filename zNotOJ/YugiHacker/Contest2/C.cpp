#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define name "CNTPALIN"

int const N = 5e5 + 5;
int const BASE = 256;
int const NMOD = 2;
int const MODS[] = {(int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277};

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
};

int n;
string s1, s2;

int pw[NMOD][N];
int hs1[NMOD][N];
int hs2[NMOD][N];

void Init()
{
    s2 = s1;
    reverse(all(s2));
    n = sz(s1);
    s1 = " " + s1;
    s2 = " " + s2;

    REP(k, NMOD)
    {
        pw[k][0] = 1;
        FOR(i, 1, n)
        {
            pw[k][i] = 1ll * pw[k][i - 1] * BASE % MODS[k];
            hs1[k][i] = (hs1[k][i - 1] + 1ll * s1[i] * pw[k][i - 1]) % MODS[k];
            hs2[k][i] = (hs2[k][i - 1] + 1ll * s2[i] * pw[k][i - 1]) % MODS[k];
        }
    }
}

Hash GetHash(int l, int r, int hs[NMOD][N])
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

bool isPalin(int l, int r)
{
    if (l >= r) return true;
    if (l < 1 || r > n) return false;
    return GetHash(l, r, hs1) == GetHash(n - r + 1, n - l + 1, hs2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> s1;

    Init();

    // I hate manacher :v
    long long res = 0;
    FOR(i, 1, n)
    {
        int l = 1;
        int r = n;
        int maxLen = l;

        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (isPalin(i - mid + 1, i + mid - 1))
            {
                maxLen = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }

        res += maxLen;
    
        l = 0;
        r = n;
        maxLen = l;
        
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (isPalin(i - mid + 1, i + mid))
            {
                maxLen = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }

        res += maxLen;
    }

    cout << res;

    return 0;
}