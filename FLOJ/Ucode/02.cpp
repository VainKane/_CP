#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)

struct Query
{
    int type, l, r;
};

int const N = 1e5 + 5;
int const MOD = 1e9 + 7;

int n, q;

Query qr[N];
int pre[3][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, q) 
    {
        int type, l, r;
        cin >> type >> l >> r;
        qr[i] = {type, l, r};
    }

    int cnt = 0;

    FORD(i, q, 1)
    {
        int type = qr[i].type;
        int l = qr[i].l;
        int r = qr[i].r;

        cnt = (cnt + pre[2][i]) % MOD;

        if (type == 2) 
        {
            pre[2][r] = (pre[2][r] + cnt + 1) % MOD;
            pre[2][l - 1] = (pre[2][l - 1] - cnt - 1) % MOD;
        }
        else 
        {
            pre[1][l] = (pre[1][l] + cnt + 1) % MOD;
            pre[1][r + 1] = (pre[1][r + 1] - cnt - 1) % MOD;
        }
    }

    int res = 0;
    FOR(i, 1, n)
    {
        res = (1ll * res + pre[1][i] % MOD + MOD) % MOD;
        cout << res << ' ';
    }

    return 0;
}