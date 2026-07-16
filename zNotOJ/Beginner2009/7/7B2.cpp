#include <bits/stdc++.h>

using namespace std;

int n;

int c[10][10];
int dx[] {-1, 0, 1, 0};
int dy[] {0, 1, 0, -1};

int x = 1;
int y = 1;

int d = 2;

int res = 0;

void Go(int &d, int &x, int &y, int cnt)
{
    int nextx = x + dx[d];
    int nexty = y + dy[d];

    // cout << cnt << ' ' << x << ' ' << y << '\n';
    c[x][y] = 2;
    res = max(res, cnt);

    if (c[nextx][nexty] == 0)
    {
        Go(d, nextx, nexty, cnt + 1);
    }
    if (c[nextx][nexty] == 1)
    {
        for (int i = 1; i <= 3; i += 2)
        {
            int d1 = (d + i) % 4;
            nextx = x + dx[d1];
            nexty = y + dy[d1];

            int tmp[10][10];

            for (int i = 0; i <= 9; i++)
            {
                for (int j = 0; j <= 9; j++)
                {
                    tmp[i][j] = c[i][j];
                }
            }

            if (c[nextx][nexty] == 0)
            {
                Go(d1, nextx, nexty, cnt + 1);
            }

            for (int i = 0; i <= 9; i++)
            {
                for (int j = 0; j <= 9; j++)
                {
                    c[i][j] = tmp[i][j];
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        c[s[1] - '0'][s[0] - 'A' + 1] = 1;
    }

    for (int i = 0; i <= 9; i++)
    {
        c[i][0] = c[i][9] = 1;
        c[0][i] = c[9][i] = 1;
    }

    Go(d, x, y, 0);

    // cout << '\n';

    // for (int i = 0; i <= 9; i++)
    // {
    //     for (int j = 0; j <= 9; j++)
    //     {
    //         cout << c[i][j] << ' ';
    //     }

    //     cout << '\n';
    // }

    cout << res;

    return 0;
}