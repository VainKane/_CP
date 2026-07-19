#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)

int const N = 1e6 + 5;
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

int n;
char s1[N];
char s2[N];

int pw[NMOD][N];
int hs1[NMOD][N];
int hs2[NMOD][N];

void Init()
{
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

char GetRev(char x)
{
    if (x == 'E') return 'W';
    if (x == 'W') return 'E';
    if (x == 'N') return 'S';
    return 'N';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n; n--;
    FOR(i, 1, n) cin >> s1[i];
    FOR(i, 1, n)
    {
        char ch; cin >> ch;
        s2[n - i + 1] = GetRev(ch);
    }

    Init();

    FOR(i, 1, n) if (GetHash(1, i, hs2) == GetHash(n - i + 1, n, hs1))
    {
        cout << "NO";
        return 0;
    }
    cout << "YES";

    return 0;
}