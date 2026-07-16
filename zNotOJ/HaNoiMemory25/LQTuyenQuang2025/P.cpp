#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 2e5 + 5;
int const oo = 1e9;
int const LOG = 21;

int n, q;
int a[N];

int c[25][25];

void Floyd()
{
    memset(c, 0x3f, sizeof c);

    FOR(i, 1, n)
    {
        for (int tmp = a[i]; tmp; tmp ^= tmp & -tmp)
        {
            int u = __builtin_ctz(tmp & -tmp);
            for (int haha = a[i]; haha; haha ^= haha & -haha)
            {
                int v = __builtin_ctz(haha & -haha);
                c[u][v] = c[v][u] = 1;
            }
        }
    }

    REP(k, LOG) REP(i, LOG) REP(j, LOG) mini(c[i][j], c[i][k] + c[k][j]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];

    Floyd();

    while (q--)
    {
        int u, v;
        cin >> u >> v;

        if (a[u] & a[v]) 
        {
            cout << "1\n";
            continue;
        }

        int res = oo;

        for (int tmp = a[u]; tmp; tmp ^= tmp & -tmp)
        {
            int i = __builtin_ctz(tmp & -tmp);
            for (int haha = a[v]; haha; haha ^= haha & -haha)
            {
                int j = __builtin_ctz(haha & -haha);
                mini(res, c[i][j]);
            }
        }

        if (res == oo) cout << "-1\n";
        else cout << res + 1 << '\n';
    }

    return 0;
}