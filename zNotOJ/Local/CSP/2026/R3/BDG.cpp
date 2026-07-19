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
#define name "BDQ"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 2e5 + 5;
int const BASE = 256;
int const NMOD = 2;
int const MODS[] = {(int)1e9 + 2277, (int)1e9 + 5277};

struct Hash
{
    int x[NMOD];
    Hash() { memset(x, 0, sizeof x); }

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

int n, m;

char s[N];
int pw[NMOD][N];
int hs[NMOD][N];

map<Hash, int> mp1;
map<pair<Hash, Hash>, int> mp2;

void Init()
{
    REP(k, NMOD)
    {
        pw[k][0] = 1;
        FOR(i, 1, 2e5) pw[k][i] = 1LL * pw[k][i - 1] * BASE % MODS[k];
    }
}

Hash GetHash(int l, int r)
{
    if (l < 1 || r > m || l > r) return Hash();
    Hash res;

    REP(k, NMOD)
    {
        int tmp = hs[k][r] - hs[k][l - 1];
        if (tmp < 0) tmp += MODS[k];

        res.x[k] = 1LL * tmp * pw[k][m - l] % MODS[k];
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    Init();

    int t; cin >> t;
    while (t--)
    {
        cin >> n >> m;

        mp1.clear(); mp2.clear();

        ll res = 0;
        FOR(i, 1, n)
        {
            FOR(i, 1, m) cin >> s[i];
            REP(k, NMOD) FOR(i, 1, m) hs[k][i] = (hs[k][i - 1] + 1LL * pw[k][i - 1] * s[i]) % MODS[k];
        
            Hash hs = GetHash(1, m);
            FOR(j, 1, m)
            {
                Hash hs1 = GetHash(1, j - 1);
                Hash hs2 = GetHash(j + 1, m);

                pair<Hash, Hash> p = {hs1, hs2};
                res += mp2[p] - mp1[hs];
                mp2[p]++;
            }

            mp1[hs]++;
        }

        cout << res << '\n';
    }

    return 0;
}