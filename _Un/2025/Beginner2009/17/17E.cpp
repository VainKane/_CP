#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define ID(i, j, n) ((i - 1) * (n) + (j))
#define sz(v) ((int)(v).size())
#define F first
#define S second
#define name "17E"

int const N = 1010;
int const NMOD = 1;
int const MOD[] = {(int)1e9 + 9277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9 + 9277};
int const P = 1e7 + 19;
int const BASE = 256;

struct Hash 
{
    int val[NMOD];

    Hash() 
    { 
        memset(val, 0, sizeof val); 
    }

    bool operator == (const Hash &other) const 
    {
        REP(k, NMOD) if (val[k] != other.val[k]) return false;
        return true;
    }

    bool operator < (const Hash &other) const 
    {
        REP(k, NMOD) if (val[k] != other.val[k]) return val[k] < other.val[k];
        return false;
    }
};

struct HashTable
{
    vector<pair<int, int>> hs[P + 5];

    int GetKey(int hash)
    {
        return hash % P;
    }

    int Insert(int key)
    {
        int hsKey = GetKey(key);
        
        for (auto &p : hs[hsKey]) if (p.F == key)
        {
            p.S++;
            return p.S;
        }

        hs[hsKey].push_back({key, 1});
        return 1;
    }
};

int m, n;
int a, b;
char s[N][N];

int pw[NMOD][N * N + 5];
int hs[NMOD][N][N];

HashTable table;
int MAX;

void Init() 
{
    MAX = N * N;
    
    REP(k, NMOD) 
    {
        pw[k][0] = 1;
        FOR(i, 1, MAX) pw[k][i] = (1ll * pw[k][i - 1] * BASE) % MOD[k];

        FOR(i, 1, m) FOR(j, 1, n)
            hs[k][i][j] = (hs[k][i - 1][j] + hs[k][i][j - 1]
                - hs[k][i - 1][j - 1] + 1ll * s[i][j] * pw[k][ID(i, j, n)] + MOD[k]) % MOD[k];
    }
}

Hash Get(int i, int j, int u, int v) 
{
    Hash res;
    if (i > u || j > v) return res;
    
    REP(k, NMOD) 
    {
        int tmp = (hs[k][u][v] - hs[k][u][j - 1] - hs[k][i - 1][v] + hs[k][i - 1][j - 1]) % MOD[k];
        if (tmp < 0) tmp += MOD[k];

        res.val[k] = (1ll * tmp * pw[k][MAX - ID(i, j, n)]) % MOD[k];
    }

    return res;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    cin.ignore();

    FOR(i, 1, m)
    {
        string str;
        getline(cin, str);
        FOR(j, 1, n) s[i][j] = str[j - 1];
    }
    cin >> a >> b;

    Init();

    int ma = -1;
    Hash maxHash;

    FOR(i, 1, m - a + 1) FOR(j, 1, n - b + 1) 
    {
        Hash hash = Get(i, j, i + a - 1, j + b - 1);
        int tmp = table.Insert(hash.val[0]); 
        
        if (tmp > ma)
        {
            ma = tmp;
            maxHash = hash;
        }  
    }

    bool first = true;

    cout << a << ' ' << b << '\n';
    FOR(i, 1, m - a + 1) FOR(j, 1, n - b + 1)
    {
        if (Get(i, j, i + a - 1, j + b - 1) == maxHash) 
        {
            if (first)
            {
                FOR(u, i, i + a - 1)
                {
                    FOR(v, j, j + b - 1) cout << s[u][v];
                    cout << '\n';
                }
                cout << ma << '\n';

                first = false;
            }
            cout << i << ' ' << j << '\n';
        }
    }
    
    return 0;
}