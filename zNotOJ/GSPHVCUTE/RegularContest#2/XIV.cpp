#include <bits/stdc++.h>

using namespace std;

#define name "pushingrocks"

int const N = 2009;
int const MOD = 998244353;

int m, n;
int a[N][N];

int cntD[N][N], cntR[N][N];
int l[N][N], u[N][N];

int posL[N], posU[N];
int sumL[N], sumU[N];

void Add(int &x, int y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

void Sub(int &x, int y)
{
    x -= y;
    if (x < 0) x += MOD;
}

void Init()
{
    for (int i = m; i >= 1; i--)
    {
        for (int j = n; j >= 1; j--)
        {
            cntR[i][j] = cntR[i][j + 1] + a[i][j + 1];
            cntD[i][j] = cntD[i + 1][j] + a[i + 1][j];
        }
    }

    for (int j = 1; j <= n; j++) l[1][j] = (cntR[1][1] <= n - j);
    for (int i = 1; i <= m; i++) u[i][1] = (cntD[1][1] <= m - i);

    for (int i = 1; i <= m; i++)
    {
        posU[i] = 1;
        sumU[i] = u[i][1];
    }
    for (int j = 1; j <= n; j++)
    {
        posL[j] = 1;
        sumL[j] = l[1][j];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char x; cin >> x;
            if (x == 'R') a[i][j] = 1;
        }
    }

    if (m * n == 1)
    {
        cout << (a[1][1] + 1) % 2;
        return 0;
    }

    Init();
    
    for (int i = 2; i <= m; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            while (posU[i] < j && cntR[i][posU[i]] > n - j)
            {
                Sub(sumU[i], u[i][posU[i]]);
                posU[i]++;
            }

            while (posL[j] < i && cntD[posL[j]][j] > m - i)
            {
                Sub(sumL[j], l[posL[j]][j]);
                posL[j]++;
            }

            l[i][j] = sumU[i];
            u[i][j] = sumL[j];

            Add(sumU[i], u[i][j]);
            Add(sumL[j], l[i][j]);
        }
    }

    cout << (l[m][n] + u[m][n]) % MOD;

    return 0;
}