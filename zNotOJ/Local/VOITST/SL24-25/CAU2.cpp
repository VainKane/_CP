#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define name "CAU2"

int const N = 2009;
int const BASE = 256;
int const NMOD = 2;
int const MOD[] = {(int)1e9 + 2277, (int)1e9 + 5277};

struct Hash
{
    int x[NMOD];
    Hash()
    {
        memset(x, 0, sizeof x);
    }

    bool operator == (Hash const other) const
    {
        REP(i, NMOD) if (x[i] != other.x[i]) return false;
        return true;
    }
};

int n;
string s, rev;

int pw[NMOD][N];
int hs1[NMOD][N];
int hs2[NMOD][N];

void Init()
{
    rev = s;
    reverse(all(rev));

    s = " " + s;   
    rev = " " + rev;
    n = s.size() - 1;

    REP(k, NMOD)
    {
        pw[k][0] = 1;
        FOR(i, 1, n) pw[k][i] = 1ll * pw[k][i - 1] * BASE % MOD[k];
        FOR(i, 1, n) 
        {
            hs1[k][i] = (hs1[k][i - 1] + 1ll * s[i] * pw[k][i - 1]) % MOD[k];
            hs2[k][i] = (hs2[k][i - 1] + 1ll * rev[i] * pw[k][i - 1]) % MOD[k];
        }
    }
}

Hash GetHash(int l, int r, int hs[NMOD][N])
{
    Hash res;
    REP(k, NMOD)
    {
        int tmp = hs[k][r] - hs[k][l - 1];
        if (tmp < 0) tmp += MOD[k];
        res.x[k] = 1ll * tmp * pw[k][n - l + 1] % MOD[k];
    }
    return res;
}

bool isPalin(int l, int r)
{
    return GetHash(l, r, hs1) == GetHash(n - r + 1, n - l + 1, hs2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> s;
    
    Init();
    vector<int> a, b;
    
    FOR(i, 1, n) FOR(j, i, n) if (isPalin(i, j)) 
    {
        a.push_back(i);
        b.push_back(j);
    }

    sort(all(a));
    
    long long res = 0;
    for (auto &x : b) res += a.end() - upper_bound(all(a), x);
    cout << res;

    return 0;
}