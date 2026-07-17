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

int const N = 5009;
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
};

int n, k;
string s1, s2;

int pw[NMOD][N];
int hs1[NMOD][N], hs2[NMOD][N];
int ehs1[NMOD][N], ehs2[NMOD][N];

void Build(int hs[NMOD][N], string s, bool odd)
{
    REP(k, NMOD) FOR(i, 1, n)
    {
        hs[k][i] = hs[k][i - 1];
        if ((i & 1) != odd) continue;
        hs[k][i] = (hs[k][i] + 1LL * pw[k][i - 1] * s[i]);
    }
}

void Init()
{
    n = sz(s1);
    
    s2 = s1;
    reverse(all(s2));

    s1 = " " + s1;
    s2 = " " + s2;

    REP(k, NMOD) 
    {
        pw[k][0] = 1;
        FOR(i, 1, n) pw[k][i] = 1LL * pw[k][i - 1] * BASE % MODS[k];
    }

    Build(hs1, s1, 1);
    Build(hs2, s2, 1);
    Build(ehs1, s1, 0);
    Build(ehs2, s2, 0);
}

Hash GetHs(int l, int r, int hs[NMOD][N])
{
    Hash res;

    REP(k, NMOD)
    {
        int tmp = hs[k][r] - hs[k][l - 1];
        if (tmp < 0) tmp += MODS[k];
        res.x[k] = 1LL * tmp * pw[k][n - l] % MODS[k];
    }

    return res;
}

bool Check(int l, int r)
{
    if (l & 1) return GetHs(l, r, hs1) == GetHs(n - r + 1, n - l + 1, hs2);
    else return GetHs(l, r, ehs1) == GetHs(n - r + 1, n - l + 1, ehs2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s1 >> k;
    Init();

    // vector<string> v;
    // FOR(i, 1, n) FOR(j, i, n) if (Check(i, j))
    // {
    //     string s = "";
    //     FOR(k, i, j) s += s1[k];
    //     v.push_back(s);
    // }

    // sort(all(v));
    // cout << v[k - 1];

    cout << Check(1, 1);

    return 0;
}