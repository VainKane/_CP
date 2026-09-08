#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 1e5 + 5;

int n;
int w[N];
vector<int> adj[N];

long long f[N][2];

vector<int> topo;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> w[i];
    FOR(i, 2, n)
    {
        int u, tmp;
        cin >> u >> tmp;
        adj[++u].push_back(i);
        adj[i].push_back(u);
    }

    DFS(1, -1);
    cout << max(f[1][0], f[1][1]);

    return 0;
}