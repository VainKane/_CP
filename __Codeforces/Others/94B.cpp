#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int m;
bool ok[6][6];

bool Check()
{
    FOR(i, 1, 5) FOR(j, i + 1, 5) FOR(k, j + 1, 5)
    {
        if (ok[i][j] == ok[j][k] && ok[i][j] == ok[i][k]) return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m;
    FOR(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        ok[u][v] = ok[v][u] = true;
    }

    cout << (Check() ? "WIN" : "FAIL");

    return 0;
}