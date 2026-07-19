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

int const N = 3e6 + 5;
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
        REP(k, NMOD) if (x[k] != other.x[k]) return false;
        return true;
    }
};

int n;
string s[(int)5e5 + 5];

int pw[NMOD][N];
map<Hash, int> dp;

Hash GetHash(int l, int r, string &s)
{
    Hash res;
    if (l > r) return res;
    REP(k, NMOD) FOR(i, l, r) res.x[k] = (res.x[k] + 1ll * s[i] * pw[k][i - l]) % MODS[k];
    return res;
}

bool cmp(string &s1, string &s2)
{
    if (sz(s1) != sz(s2)) return sz(s1) < sz(s2);
    REP(i, min(sz(s1), sz(s2)) - 1) if (s1[i] != s2[i]) return s1[i] < s2[i];
    return true;
}

void Init()
{
    REP(k, NMOD)
    {
        pw[k][0] = 1;
        FOR(i, 1, 3e6) pw[k][i] = 1ll * pw[k][i - 1] * BASE % MODS[k];
    }

    sort(s + 1, s + n + 1, cmp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n)
    {
        cin >> s[i];
        s[i] = " " + s[i];
    }

    Init();
    int res = 1;
    
    FOR(i, 1, n)
    {
        Hash hs1 = GetHash(1, sz(s[i]) - 1, s[i]);
        Hash hs2 = GetHash(2, sz(s[i]) - 1, s[i]);

        int x = max(dp[hs1], dp[hs2]) + 1;
        dp[hs1] = dp[hs2] = x;

        maxi(res, x);
    }

    cout << res;

    return 0;
}