#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define all(v) v.begin(), v.end()

int const N = 1509;
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

int n, k;
string s, status;

int cnt[N];

int pw[NMOD][N];
int hs[NMOD][N];

void Init()
{
    n = s.size();
    s = " " + s;

    FOR(i, 1, n) cnt[i] = cnt[i - 1] + (status[s[i] - 'a'] == '0');

    REP(k, NMOD)
    {
        pw[k][0] = 1;
        FOR(i, 1, n)
        {
            pw[k][i] = 1ll * pw[k][i - 1] * BASE % MODS[k];
            hs[k][i] = (hs[k][i - 1] + 1ll * s[i] * pw[k][i - 1]) % MODS[k];
        }
    }
}

Hash GetHash(int l, int r)
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s >> status;
    cin >> k;

    Init();

    vector<Hash> v;
    
    FOR(l, 1, n) FOR(r, l, n) 
    {
        if (cnt[r] - cnt[l - 1] > k) break;
        v.push_back(GetHash(l, r));
    } 

    sort(all(v));
    v.erase(unique(all(v)), v.end());

    cout << v.size();

    return 0;
}