#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define all(v) v.begin(), v.end()
#define F first
#define S second

int const N = 1010;
int const NMOD = 1;
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

int m, n;
int a, b;
char s[N][N];

int pw[NMOD][N * N];
int hs[NMOD][N][N];

int MAX;

map<Hash, vector<pair<int, int>>> mp;

int GetId(int i, int j)
{
    return (i - 1) * n + j;
}

void Init()
{
    MAX = (m + 1) * (n + 1) + 1;

    REP(k, NMOD)
    {
        pw[k][0] = 1;
        FOR(i, 1, MAX) pw[k][i] = (1ll * pw[k][i - 1] * BASE) % MOD[k]; 

        FOR(i, 1, m) FOR(j, 1, n) 
            hs[k][i][j] = (1ll * hs[k][i - 1][j] + hs[k][i][j - 1] 
                        - hs[k][i - 1][j - 1] + 1ll * s[i][j] * pw[k][GetId(i, j)] + MOD[k]) % MOD[k]; 
    }
}

Hash Get(int i, int j, int u, int v)
{
    Hash res;
    if (i > u || j > v) return res;

    REP(k, NMOD)
    {
        int tmp = (1ll * hs[k][u][v] - hs[k][u][j - 1] - hs[k][i - 1][v] + hs[k][i - 1][j - 1] + 2ll * MOD[k]) % MOD[k];
        res.val[k] = (1ll * tmp * pw[k][MAX - GetId(i, j)]) % MOD[k];
    }

    return res;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);

    cin >> m >> n;
    cin.ignore(1);
    FOR(i, 1, m)
    {
        string str;
        getline(cin, str);

        // if (str.size() < n) return 0;

        str = " " + str;
        FOR(j, 1, n) s[i][j] = str[j];
    }
    cin >> a >> b;

    Init();

    int ma = -1;
    Hash hsMa;

    FOR(i, 1, m - a + 1) FOR(j, 1, n - b + 1)
    {
        Hash tmp = Get(i, j, i + a - 1, j + b - 1);
        vector<pair<int, int>> &v = mp[tmp];
        v.push_back({i, j});

        if ((int)v.size() > ma)
        {
            ma = v.size();
            hsMa = tmp;
        }
    }

    vector<pair<int, int>> &res = mp[hsMa];

    cout << a << ' ' << b << '\n';
    FOR(i, res[0].F, res[0].F + a - 1)
    {
        FOR(j, res[0].S, res[0].S + b - 1) cout << s[i][j];
        cout << '\n';
    }
    cout << ma << '\n';
    for (auto p : res) cout << p.F << ' ' << p.S << '\n';

    return 0;
}