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

int const N = 1e5 + 5;
int const M = 1009;
int const MOD = 1e9 + 7;

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

int n, m;
string s[N], t;

int pw[NMOD][N];
int hs[NMOD][N];

vector<int> len;
vector<Hash> hsLen[N];

int dp[N];

Hash GetHash(int l, int r)
{
    Hash res;

    REP(k, NMOD)
    {
        int tmp = hs[k][r] - hs[k][l - 1];
        if (tmp < 0) tmp += MODS[k];
        res.x[k] = 1LL * tmp * pw[k][m - l] % MODS[k];
    }

    return res;
}

Hash LonelyHash(string &s)
{
    s = " " + s;
    Hash res;
    
    REP(k, NMOD) 
    {
        FOR(i, 1, sz(s) - 1) res.x[k] = (res.x[k] + 1LL * pw[k][i - 1] * s[i]) % MODS[k];
        res.x[k] = 1LL * res.x[k] * pw[k][m - 1] % MODS[k];
    }
    
    return res;
}

void Init()
{
    m = sz(t);
    t = " " + t;

    REP(k, NMOD)
    {
        pw[k][0] = 1;
        FOR(i, 1, m)
        {
            pw[k][i] = 1LL * pw[k][i - 1] * BASE % MODS[k];
            hs[k][i] = (hs[k][i - 1] + 1LL * pw[k][i - 1] * t[i]) % MODS[k];
        }
    }

    FOR(i, 1, n) if (sz(s[i]) <= m)
    {
        len.push_back(sz(s[i]));
        hsLen[sz(s[i])].push_back(LonelyHash(s[i]));
    }

    sort(all(len));
    len.erase(unique(all(len)), len.end());
    FOR(i, 1, m) sort(all(hsLen[i]));
}

inline int Count(int &l, Hash hs)
{
    return upper_bound(all(hsLen[l]), hs) - lower_bound(all(hsLen[l]), hs);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> s[i];
    cin >> t;

    Init();

    dp[0] = 1;
    FOR(i, 1, m) for (auto &j : len)
    {
        if (j > i) break;
        dp[i] = (dp[i] + 1LL * dp[i - j] * Count(j, GetHash(i - j + 1, i))) % MOD;
    }

    cout << dp[m];

    return 0;
}