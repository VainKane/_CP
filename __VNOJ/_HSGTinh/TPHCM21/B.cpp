#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 5;

int n, p;
int a, b, r;

int h[N];
bool visited[N];

void BFS(int s)
{
    queue<int> qu;

    int v1 = (s + a) % p;
    int v2 = (s + b) % p;
    int v3 = (s + a + b) % p;

    qu.push(v1);
    qu.push(v2);
    qu.push(v3);

    h[v1] = h[v2] = h[v3] = 1;

    while (!qu.empty())
    {
        int u = qu.front();
        qu.pop();

        v1 = (u + a) % p;
        v2 = (u + b) % p;
        v3 = (u + a + b) % p;

        if (!h[v1])
        {
            h[v1] = h[u] + 1;
            qu.push(v1);
        }
        if (!h[v2])
        {
            h[v2] = h[u] + 1;
            qu.push(v2);
        }
        if (!h[v3])
        {
            h[v3] = h[u] + 1;
            qu.push(v3);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> p;
    cin >> a >> b >> r;

    BFS(n);
    cout << (h[r] ? h[r] : -1);

    return 0;
}