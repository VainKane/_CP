#include <bits/stdc++.h>

using namespace std;

int const N = 509;

int n;
int a[N][N];

bool visisted[N][N];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void DFS(int x, int y, int limit)
{
    visisted[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int xnew = x + dx[i];
        int ynew = y + dy[i];

        if (visisted[xnew][ynew] || abs(a[xnew][ynew] - a[x][y]) > limit) continue;
        DFS(xnew, ynew, limit);
    }
}

void Solve()
{
    int l = 0;
    int r = 1e6;
    int res;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        
        memset(visisted, 0, sizeof visisted);
        DFS(1, 1, mid);

        if (visisted[n][n])
        {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    memset(a, 0x3f, sizeof a);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> a[i][j];

    Solve();

    return 0;
}