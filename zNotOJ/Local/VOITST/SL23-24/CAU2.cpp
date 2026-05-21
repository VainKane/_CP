#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define mp make_pair
#define pb push_back
#define name "CAU2"

int const N = 6e5 + 5;
int const oo = 3e5;
int const BASE = 256;
int const NMOD = 3;
int const MODS[] = {(int)1e9 + 7};

struct Hash
{
    int x[NMOD];

    Hash()
    {
        memset(x, 0, sizeof x);
    }

    bool operator < (Hash const other) const
    {
        REP(k, NMOD) if (x[k] != other.x[k]) return x[k] < other.x[k];
        return false;
    }

    bool operator == (Hash const other) const
    {
        REP(k, NMOD) if (x[k] != other.x[k]) return false;
        return true;
    }
};

int n, m;

int pw[NMOD][N];
int hs[NMOD][N];

vector<pair<Hash, Hash>> mark[26];

void Init()
{
    REP(k, NMOD)
    {
        pw[k][0] = 1;
        FOR(i, 1, oo) pw[k][i] = 1ll * pw[k][i - 1] * BASE % MODS[k];
    }
}

Hash GetHash(int l, int r)
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

void HashInto(string s)
{
    int n = sz(s);
    s = " " + s;

    REP(k, NMOD) FOR(i, 1, n)
        hs[k][i] = (hs[k][i - 1] + 1ll * s[i] * pw[k][i - 1]) % MODS[k];

    FOR(i, 2, n - 1) mark[s[i] - 'a'].pb({GetHash(1, i - 1), GetHash(i + 1, n)});
    mark[s[1] - 'a'].pb({Hash(), GetHash(2, n)});
    mark[s[n] - 'a'].pb({GetHash(1, n - 1), Hash()});
}

bool Solve(string s)
{
    int n = sz(s);
    s = " " + s;

    REP(k, NMOD) FOR(i, 1, n)
        hs[k][i] = (hs[k][i - 1] + 1ll * s[i] * pw[k][i - 1]) % MODS[k];

    REP(c, 26)
    {
        if (s[1] - 'a' != c && binary_search(all(mark[c]), mp(Hash(), GetHash(2, n)))) return true;
        if (s[n] - 'a' != c && binary_search(all(mark[c]), mp(GetHash(1, n - 1), Hash()))) return true;
        FOR(i, 2, n - 1) if (s[i] - 'a' != c && binary_search(all(mark[c]), mp(GetHash(1, i - 1), GetHash(i + 1, n)))) return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    Init();

    cin >> n >> m;
    FOR(i, 1, n)
    {
        string s; cin >> s;
        HashInto(s);
    }

    REP(i, 26)
    {
        sort(all(mark[i]));
        mark[i].erase(unique(all(mark[i])), mark[i].end());
    }

    while (m--)
    {
        string s; cin >> s;
        cout << (Solve(s) ? "YES\n" : "NO\n");
    }

    return 0;
}