#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)

int const N = 2e5 + 5;
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
string s, t;

int pw[NMOD][N];
int hs1[NMOD][N];
int hs2[NMOD][N];

void Init()
{
    s = " " + s + s;
    t = " " + t;
    n = t.size() - 1;

    REP(k, NMOD)
    {
        pw[k][0] = 1;
        
        FOR(i, 1, 2 * n)
        {
            pw[k][i] = 1ll * pw[k][i - 1] * BASE % MODS[k];
            hs1[k][i] = (hs1[k][i - 1] + 1ll * s[i] * pw[k][i - 1]) % MODS[k];
        }
        FOR(i, 1, n)
            hs2[k][i] = (hs2[k][i - 1] + 1ll * t[i] * pw[k][i - 1]) % MODS[k];
    }
}

Hash GetHash(int l, int r, int hs[NMOD][N])
{
    Hash res;

    REP(k, NMOD)
    {
        int tmp = hs[k][r] - hs[k][l - 1];
        if (tmp < 0) tmp += MODS[k];

        res.x[k] = 1ll * tmp * pw[k][2 * n - l + 1] % MODS[k];
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s >> t;

    Init();
    long long res = 0;
    
    FOR(i, 1, n)
    {
        if (GetHash(i, i + n - 1, hs1) == GetHash(1, n, hs2)) res += n;
        else
        {
            int l = i - 1;
            int r = i + n - 1;
            int pos = l;

            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (GetHash(i, mid, hs1) == GetHash(1, mid - i + 1, hs2))
                {
                    pos = mid;
                    l = mid + 1;
                }
                else r = mid - 1;
            }

            res += GetHash(pos + 2, i + n - 1, hs1) == GetHash(pos - i + 3, n, hs2);
        }
    }

    cout << res;

    return 0;
}