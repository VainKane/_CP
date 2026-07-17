#include <bits/stdc++.h>

using namespace std;

int const N = 59;
int const MOD = 2017;

int n;
int m;
int k;

vector<int> adj[N];

struct Matrix
{
    int x[N][N];

    Matrix()
    {
        memset(x, 0, sizeof x);
    }
};

Matrix Multi(Matrix a, Matrix b)
{
    Matrix res;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                res.x[i][j] = (res.x[i][j] + 1ll * a.x[i][k] * b.x[k][j]) % MOD;
            }
        }
    }

    return res;
}

Matrix Pow(Matrix a, int b)
{
    Matrix res;
    for (int i = 1; i <= n; i++) res.x[i][i] = 1;

    while (b)
    {
        if (b & 1)
        {
            res = Multi(res, a);
        }
        b >>= 1;
        a = Multi(a, a);
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("23D.inp", "r", stdin);
    // freopen("23D.out", "w", stdout);

    cin >> n >> m >> k;

    while (m--)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    Matrix t;
    for (int v = 1; v <= n; v++)
    {
        for (auto u : adj[v])
        {
            t.x[u][v]++;
        }
    }

    t = Pow(t, k - 1);

    Matrix b;

    for (auto v : adj[1])
    {
        b.x[v][1]++;
    }

    t = Multi(t, b);

    cout << t.x[n][1];

    return 0;
}