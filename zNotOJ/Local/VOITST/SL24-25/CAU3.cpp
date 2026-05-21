#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "CAU3"

int const N = 103;

int m, n;
int row;

int initA[N][N], initB[N][N];
int a[N][N], b[N][N];

bool Try(int pos)
{
    if (pos > n) 
    {
        // cout << "After row " << row << ":\n";
        // cout << "Board A:\n";
        // FOR(i, 1, m) 
        // {
        //     FOR(j, 1, n) cout << a[i][j] << ' ';
        //     cout << '\n';
        // }

        // cout << "Board B:\n";
        // FOR(i, 1, m) 
        // {
        //     FOR(j, 1, n) cout << b[i][j] << ' ';
        //     cout << '\n';
        // }
        // cout << '\n';

        return true;
    }
    FOR(i, 0, 1)
    {
        a[row][pos] = initA[row][pos];
        b[row][pos] = initB[row][pos];

        if (i) swap(a[row][pos], b[row][pos]);
        
        if (a[row][pos] <= a[row - 1][pos] || a[row][pos] <= a[row][pos - 1]) continue;
        if (b[row][pos] <= b[row - 1][pos] || b[row][pos] <= b[row][pos - 1]) continue;

        if (Try(pos + 1)) return true;
    }
    return false;
}

bool Solve()
{
    for (row = 1; row <= m; row++) if (!Try(1)) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    int t; cin >> t;
    while (t--)
    {
        cin >> m >> n;

        FOR(i, 1, m) FOR(j, 1, n) cin >> initA[i][j];
        FOR(i, 1, m) FOR(j, 1, n) cin >> initB[i][j];

        cout << (Solve() ? "Yes\n" : "No\n");        
    }

    return 0;
}