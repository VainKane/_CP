#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 10;

int n;
int m;

int parent[N];
int setRank[N];

void MakeSet()
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        setRank[i] = 1;
    }
}

int Find(int v)
{
    if (v == parent[v]) return v;
    return parent[v] = Find(parent[v]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if (a != b)
    {
        if (setRank[a] < setRank[b]) swap(a, b);
        parent[b] = a;
        setRank[a] += setRank[b];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    
    MakeSet();
    for (int i = 1; i <= m; i++)
    {
        int type, u, v;
        cin >> type >> u >> v;

        if (type == 1) Union(u, v);
        else cout << (Find(u) == Find(v)) << '\n';
    }

    return 0;
}