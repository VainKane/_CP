#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())

int const N = 5009;
int const BASE = 256;
int const NMOD = 1;
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

int n, m, oo;
string s1, s2;

int pw[NMOD][N];
int hs1[NMOD][N];
int hs2[NMOD][N];

void Build(int n, string s, int hs[NMOD][N])
{
    REP(k, NMOD) FOR(i, 1, n)
        hs[k][i] = (hs[k][i - 1] + 1ll * s[i] * pw[k][i - 1]) % MODS[k];
}

void Init()
{
    n = sz(s1), m = sz(s2);
    s1 = " " + s1;
    s2 = " " + s2;

    oo = max(m, n);
    REP(k, NMOD)
    {
        pw[k][0] = 1;
        FOR(i, 1, oo) pw[k][i] = 1ll * pw[k][i - 1] * BASE % MODS[k];
    }

    Build(n, s1, hs1);
    Build(m, s2, hs2);
}

Hash GetHash(int l, int r, int hs[NMOD][N])
{
    Hash res;

    REP(k, NMOD)
    {
        int tmp = hs[k][r] - hs[k][l - 1];
        if (tmp < 0) tmp += MODS[k];
        res.x[k] = 1ll * tmp * pw[k][oo - l + 1] % MODS[k];
    }

    return res;
}

int Count(Hash &hs, vector<Hash> &v)
{
    return upper_bound(all(v), hs) - lower_bound(all(v), hs);
}

bool Check(int const &len)
{
    vector<Hash> v1, v2;

    FOR(i, 1, n - len + 1) v1.push_back(GetHash(i, i + len - 1, hs1));
    FOR(i, 1, m - len + 1) v2.push_back(GetHash(i, i + len - 1, hs2));

    sort(all(v1));
    sort(all(v2));

    for (auto &hs : v1)
    {
        if (Count(hs, v1) != 1) continue;
        if (Count(hs, v2) != 1) continue;
        return true;   
    }
    
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s1 >> s2;
    Init();

    FOR(i, 1, min(m, n)) if (Check(i)) 
    {
        cout << i;
        return 0;
    }

    cout << -1;

    return 0;
}