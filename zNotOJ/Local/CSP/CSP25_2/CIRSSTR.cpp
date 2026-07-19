#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define MK(i) (1 << (i))
#define name "CIRSSTR"

int const N = 2e5 + 10;
int const NMOD = 2;
int const MOD[] = {(int)1e9 + 2277, (int)1e9 + 5277};
int const BASE = 256;

struct Hash
{
    int val[NMOD];

    Hash()
    {
        memset(val, 0, sizeof val);
    }

    bool operator < (Hash const other) const
    {
        REP(k, NMOD) if (val[k] != other.val[k]) return val[k] < other.val[k];
        return false;
    }
};

string s[2];
int len[2];

set<Hash> visited;

int pw[NMOD][N];
int hs[2][NMOD][N];

int MAX;

void Init()
{
    len[0] = s[0].size();
    len[1] = s[1].size();

    s[0] = " " + s[0] + s[0];
    s[1] = " " + s[1] + s[1];

    MAX = max(len[0], len[1]) * 2 + 1;

    REP(k, NMOD)
    {
        pw[k][0] = 1;
        FOR(i, 1, MAX) pw[k][i] = (1ll * pw[k][i - 1] * BASE) % MOD[k];

        REP(id, 2) FOR(i, 1, len[id] * 2) 
            hs[id][k][i] = (hs[id][k][i - 1] + 1ll * s[id][i] * pw[k][i]) % MOD[k]; 
    }
}

Hash GetHash(int id, int l, int r)
{
    Hash res;
    if (l > r) return res;

    REP(k, NMOD)
    {
        int tmp = hs[id][k][r] - hs[id][k][l - 1];
        if (tmp < 0) tmp += MOD[k];
        res.val[k] = (1ll * tmp * pw[k][MAX - l]) % MOD[k];
    }

    return res;
}

bool Check(int l)
{
    visited.clear();
    FOR(i, 1, len[0]) visited.insert(GetHash(0, i, i + l - 1));
    FOR(i, 1, len[1]) if (visited.count(GetHash(1, i, i + l - 1))) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen(name".inp", "r", stdin);
    // freopen(name".out", "w", stdout);

    cin >> s[0] >> s[1];
   
    Init();

    int l = 1;
    int r = min(len[0], len[1]);
    int res = 0;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (Check(mid))
        {
            res = mid;
            l = mid + 1;
        }     
        else r = mid - 1;
    }

    cout << res;

    return 0;
}