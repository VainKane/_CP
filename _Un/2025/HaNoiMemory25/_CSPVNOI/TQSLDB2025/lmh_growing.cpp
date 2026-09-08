#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

struct FenwickTree
{
    vector<long long> bit;
    int n;

    FenwickTree (int _n = 0)
    {
        n = _n;
        bit.assign(n + 5, 0);
    }

    void Update(int idx, int val)
    {
        while (idx <= n)
        {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    void Update(int l, int r, int val)
    {
        Update(l, val);
        Update(r + 1, -val);
    }

    long long Get(int idx)
    {
        long long res = 0;

        while (idx)
        {
            res += bit[idx];
            idx ^= idx & -idx;
        }

        return res;
    }

    long long Get(int l, int r)
    {
        if (l > r) return 0;
        return Get(r) - Get(l - 1);
    }
};

int const N = 5e5 + 5;

int n, m;

int par[N];
vector<int> adj[N];

int in[N], out[N];
int cnt = 0;

FenwickTree bit1, bit2;

void DFS(int u, int p)
{
    in[u] = ++cnt;
    for (auto &v : adj[u]) if (v != p) DFS(v, u);
    out[u] = cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 2, n)
    {
        cin >> par[i];
        adj[i].push_back(par[i]);
        adj[par[i]].push_back(i);
    }

    DFS(1, -1);
    bit1 = bit2 = FenwickTree(n);

    FOR(i, 1, m)
    {
        char type;
        int v, k;

        cin >> type;
        if (type == 'A')
        {
            cin >> v >> k;
            bit1.Update(in[v], k);
        }
        else if (type == 'B')
        {
            cin >> v >> k;
            bit2.Update(in[v], out[v], k);
        }
        else
        {
            cin >> v;
            cout << bit2.Get(in[v]) + bit1.Get(in[v], out[v]) << '\n';
        }
    }

    return 0;
}
