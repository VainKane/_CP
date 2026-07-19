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

int n, m;
char a[N], b[N];

int pw[NMOD][N];
int hsA[NMOD][N];
int hsB[NMOD][N];

Hash GetHash(int l, int r, int hs[NMOD][N])
{
    Hash res;
    if (l > r) return res;

    REP(k, NMOD)
    {
        int tmp = hs[k][r] - hs[k][l - 1];
        if (tmp < 0) tmp += MODS[k];

        res.x[k] = 1ll * tmp * pw[k][n - l + 1] % MODS[k];
    }

    return res;
}

void Init()
{
    REP(k, NMOD)
    {
        pw[k][0] = 1;
        FOR(i, 1, n)
        {
            pw[k][i] = 1ll * pw[k][i - 1] * BASE % MODS[k];
            hsA[k][i] = (hsA[k][i - 1] + 1ll * a[i] * pw[k][i - 1]) % MODS[k];
            hsB[k][i] = (hsB[k][i - 1] + 1ll * b[i] * pw[k][i - 1]) % MODS[k];
        }
    }
}

char Solve(int l, int r, int u, int v)
{
    int lo = 0;
    int hi = min(r - l + 1, v - u + 1);
    int dist = lo;

    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (GetHash(l, l + mid - 1, hsA) == GetHash(u, u + mid - 1, hsB))
        {
            dist = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }

    int i = l + dist;
    int j = u + dist;

    if (i > r || j > v) 
    {
        if (r - l == v - u) return '=';
        if (r - l < v - u) return '<';
        return '>';
    }
    if (a[i] < b[j]) return '<';
    return '>';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, m) cin >> b[i];

    Init();

    int q; cin >> q;
    while (q--)
    {
        int l, r, u, v;
        cin >> l >> r >> u >> v;
        cout << Solve(l, r, u, v);
    }

    return 0;
}