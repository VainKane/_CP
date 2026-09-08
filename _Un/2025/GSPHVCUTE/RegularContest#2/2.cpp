#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int u, v, w;
};

int const N = 88;

int n;
int a[N][N];

vector<Edge> edges; 
int d[N];

void BellmanFord()
{
    while (1)
    {
        bool stop = true;
        for (auto e : edges)
        {
            if (d[e.v] < d[e.u] + e.w)
            {
                d[e.v] = d[e.u] + e.w;
                stop = false;
            }
        }
        if (stop) break;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) 
        {
            cin >> a[i][j];

            if (a[i][j] == 0)
            {
                edges.push_back({i, j, 0});
                edges.push_back({j, i, 0});
            }
            else if (a[i][j] == 1) edges.push_back({i, j, 1});
            else if (a[i][j] == 2) edges.push_back({i, j, 0});
            else if (a[i][j] == -1) edges.push_back({j, i, 1});
            else edges.push_back({j, i, 0});
        }
    }

    BellmanFord();

    cout << *max_element(d + 1, d + n + 1) + 1 << '\n';
    for (int i = 1; i <= n; i++) cout << d[i] + 1 << ' ';

    return 0;
}