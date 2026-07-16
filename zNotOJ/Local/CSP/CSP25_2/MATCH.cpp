#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define MK(i) ((1 << (i)))
#define BIT(i, x) (((x) >> (i)) & 1)
#define name "MATCH"

int const N = 1e6 + 5;
int const LOG = 20;

int n, m, q;
int a[N], b[N];

int pos[N];
int last[N];

int up[N][25];
int upMin[N][25];
int p[N];

int lg[N];

void Init()
{
    memset(upMin, 0x3f, sizeof upMin);
    b[m + 1] = b[1];

    FORD(i, n, 1)
    {
        int x = b[pos[a[i]] + 1];
        up[i][0] = last[x];
        last[a[i]] = i;
    }

    FOR(j, 1, LOG) FOR(i, 1, n)
        up[i][j] = up[up[i][j - 1]][j - 1];

    FOR(i, 1, n)
    {
        p[i] = i;
        FORD(j, LOG, 0) if (BIT(j, m - 1)) p[i] = up[p[i]][j];
        if (p[i]) upMin[i][0] = p[i];
    }

    // FOR(i, 1, n) cout << p[i] << ' ';

    FOR(j, 1, LOG) FOR(i, 1, n - (i + MK(j - 1)) + 1)
        upMin[i][j] = min(upMin[i][j - 1], upMin[i + MK(j - 1)][j - 1]);
    
    FOR(i, 2, n) lg[i] = lg[i / 2] + 1;
}

int GetMin(int l, int r)
{
    int k = lg[r - l + 1];
    return min(upMin[l][k], upMin[r - MK(k) + 1][k]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen(name".inp", "r", stdin);
    // freopen(name".out", "w", stdout);

    cin >> n >> m >> q;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, m) cin >> b[i], pos[b[i]] = i;

    Init();

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << ((GetMin(l, r) <= r) ? "YES\n" : "NO\n");   
    }

    return 0;
}