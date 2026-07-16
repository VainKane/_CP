#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 109;

int n;
char a[N][N];

bool PureCols()
{
    int cnt = 0;
    FOR(j, 1, n) FOR(i, 1, n) if (a[i][j] == '.') 
    {
        cnt++;
        break;
    }
    return cnt == n;
}

bool PureRows()
{
    int cnt = 0;
    FOR(i, 1, n) FOR(j, 1, n) if (a[i][j] == '.')
    {
        cnt++;
        break;
    }
    return cnt == n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) FOR(j, 1, n) cin >> a[i][j];

    if (PureCols())
    {
        FOR(j, 1, n) FOR(i, 1, n) if (a[i][j] == '.')
        {
            cout << i << ' ' << j << '\n';
            break;
        }
    }
    else if (PureRows())
    {
        FOR(i, 1, n) FOR(j, 1, n) if (a[i][j] == '.')
        {
            cout << i << ' ' << j << '\n';
            break;
        }
    }
    else cout << -1;

    return 0;
}