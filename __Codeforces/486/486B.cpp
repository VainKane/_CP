#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 109;

int m, n;
bool a[N][N], b[N][N];

void Check(int x, int y)
{
    FOR(i, 1, m) FOR(j, 1, n) 
    {
        if (a[x][j]) return;
        if (a[i][y]) return;
    }

    cout << "NO";
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n) cin >> b[i][j];

    memset(a, 1, sizeof a);
    FOR(i, 1, m) FOR(j, 1, n) if (!b[i][j])
    {
        FOR(u, 1, n) a[i][u] = 0;
        FOR(u, 1, m) a[u][j] = 0;
    }

    FOR(i, 1, m) FOR(j, 1, n) if (b[i][j]) Check(i, j);

    cout << "YES\n";
    FOR(i, 1, m) 
    {
        FOR(j, 1, n) cout << a[i][j] << ' ';
        cout << '\n';
    }
        
    return 0;
}