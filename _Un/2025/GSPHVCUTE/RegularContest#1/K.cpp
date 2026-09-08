#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define name "flash"

int const N = 2210;

int n, m, k;

int xs, ys;
int xt, yt;

char a[N][N];
int d[N][N];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS()
{
    queue<pair<int, int>> qu;

    qu.push({xs, ys});
    a[xs][ys] = '#';
    d[xs][ys] = 0;

    while (!qu.empty())
    {
        int x = qu.front().F;
        int y = qu.front().S;
        qu.pop();

        for (int i = 0; i < 4; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                int xnew = x + j * dx[i];
                int ynew = y + j * dy[i];

                if (xnew * ynew == 0) break;
                if (xnew == m + 1 || ynew == n + 1) break;
                if (a[xnew][ynew] == '#') break;

                if (d[xnew][ynew] != -1)
                {
                    if (d[xnew][ynew] < d[x][y] + 1) break;
                    if (d[xnew][ynew] == d[x][y] + 1) continue;
                }

                qu.push({xnew, ynew});
                d[xnew][ynew] = d[x][y] + 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> m >> n >> k;

    memset(d, -1, sizeof d);

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    cin >> xs >> ys >> xt >> yt;

    BFS();
    cout << d[xt][yt];

    return 0;   
}