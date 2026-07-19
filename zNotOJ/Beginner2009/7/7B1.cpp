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

int Go(int &d, int &x, int &y)
{
    int nextx = x + dx[d];
    int nexty = y + dy[d];

    if (c[nextx][nexty] == -1) return res;
    if (c[nextx][nexty] == 1)
    {
        d = (d + 3) % 4;
        return Go(d, x, y);
    }

    res++;
    c[x][y] = -1;
    return Go(d, nextx, nexty);
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

    cout << Go(d, x, y);

    return 0;
}