#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define all(v) v.begin(), v.end()
#define name "message"

int const N = 109;
int const NMOD = 3;
int const MOD[] = {(int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9 + 9277};
int const BASE = 256;

struct Hash
{
    int val[NMOD];

    Hash()
    {
        memset(val, 0, sizeof val);
    }

    bool operator == (Hash const other) const
    {
        REP(k, NMOD) if (val[k] != other.val[k]) return false;
        return true;
    }

    bool operator < (Hash const other) const
    {
        REP(k, NMOD) if (val[k] != other.val[k]) return val[k] < other.val[k];
        return false;
    }
};

int t;
int m, n;
char s[2][N][N];

int pw[NMOD][N * N];
int hs[NMOD][2][N][N];

int GetId(int i, int j)
{
    return (i - 1) * n + j;
}

void Init()
{
    REP(k, NMOD)
    {
        REP(id, 2) FOR(i, 1, m) FOR(j, 1, n)
            hs[k][id][i][j] = (hs[k][id][i - 1][j] + hs[k][id][i][j - 1] - hs[k][id][i - 1][j - 1] 
                            + 1ll * s[id][i][j] * pw[k][GetId(i, j)] + MOD[k]) % MOD[k];
    }
}

Hash GetHash(int i, int j, int u, int v, int id)
{
    Hash res;
    if (i > u || j > v) return res;

    REP(k, NMOD)
    {
        int tmp = (hs[k][id][u][v] - hs[k][id][u][j - 1] - hs[k][id][i - 1][v] 
                + 1ll * hs[k][id][i - 1][j - 1]) % MOD[k];
        if (tmp < 0) tmp += MOD[k];
        res.val[k] = (1ll * tmp * pw[k][m * n - GetId(i, j)]) % MOD[k];
    }

    return res;
}

bool Check(int a, int b)
{
    vector<Hash> hs1;

    FOR(i, 1, m - a + 1) FOR(j, 1, n - b + 1)
        hs1.push_back(GetHash(i, j, i + a - 1, j + b - 1, 0));
    
    sort(all(hs1));

    FOR(i, 1, m - a + 1) FOR(j, 1, n - b + 1) 
        if (binary_search(all(hs1), GetHash(i, j, i + a - 1, j + b - 1, 1))) return true;

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> t;
    REP(k, NMOD)
    {
        pw[k][0] = 1;
        FOR(i, 1, 102 * 102) pw[k][i] = (1ll * pw[k][i - 1] * BASE) % MOD[k];
    }
        
    while (t--)
    {   
        cin >> m >> n;
        REP(id, 2) FOR(i, 1, m) FOR(j, 1, n) cin >> s[id][i][j];

        Init();
        int res = 0;

        int b = n;
        FOR(a, 1, m)
        {
            while (!Check(a, b) && b) b--;
            res = max(res, a * b);
        }

        cout << res << '\n';
    }

    return 0;
}