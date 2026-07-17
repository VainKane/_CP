#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 609;

int n, m, k;
bitset<N> adj[N];
bitset<N> res;

bool Clique(bitset<N> C, bitset<N> V)
{
    if (C.count() + V.count() < k) return false;
    if (C.count() == k) 
    {
        res = C;
        return true;
    }

    FOR(u, 1, n) if (V[u])
    {
        bitset<N> newC = C;
        newC[u] = 1;

        if (Clique(newC, V & adj[u])) return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;

        FOR(i, 1, n) adj[i].reset();

        FOR(i, 1, m)
        {
            int u, v;
            cin >> u >> v;

            adj[u][v] = 1;
            adj[v][u] = 1;
        }

        if (Clique(bitset<N>(), bitset<N>().set()))
        {
            FOR(i, 1, n) if (res[i]) cout << i << ' ';
            cout << '\n';
        }
        else cout << "-1\n";
    }

    return 0;
}