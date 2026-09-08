#include <bits/stdc++.h>

using namespace std;

int const N = 1009;

int m;
int n;
int q;

vector<pair<int, int>> color[(int)1e4 + 10];
int a[N][N];
int parent[N * N];
int res[N * N];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int cnt = 0;

void MakeSet()
{
    for (int i = 1; i <= m * n; i++)
    {
        parent[i] = i;
    }
}

int Find(int v)
{
    if (v == parent[v]) return v;
    return parent[v] = Find(parent[v]);
}

bool Union(int a, int b)
{
    if (b == 0) return false;

    a = Find(a);
    b = Find(b);

    if (a != b)
    {
        parent[b] = a;
    }

    return a != b;
}

int Cal(int u, int v)
{
    a[u][v] = ++cnt;
    int res = 0;

    for (int i = 0; i < 4; i++)
    {
        int p = u + dx[i];
        int q = v + dy[i];

        res += Union(a[u][v], a[p][q]);
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n >> q;
    for (int i = 1; i <= q; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int x = x1; x <= x2; x++)
        {
            for (int y = y1; y <= y2; y++)
            {
                if (!a[x][y])
                {
                    a[x][y] = i;
                    color[i].push_back({x, y});
                }
            }
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!a[i][j])
            {
                color[q + 1].push_back({i, j});
            }
        }
    }

    memset(a, 0, sizeof a);
    MakeSet();

    for (int i = q + 1; i >= 1; i--)
    {
        res[i - 1] = res[i];
        for (auto v : color[i])
        {
            res[i - 1]++;
            res[i - 1] -= Cal(v.first, v.second);
        }
    }

    for (int i = 1; i <= q; i++) cout << res[i] << '\n';

    return 0;
}