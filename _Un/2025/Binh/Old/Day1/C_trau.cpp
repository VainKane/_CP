#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 1009;

int m, n;
int a[N][N];

bool Check(int top, int bot, int left, int right)
{
    FOR(u, 2, bot - top + 1) FOR(v, 2, right - left + 1) FOR(i, top, bot - u + 1) FOR(j, left, right - v + 1)
        if (a[i][j] + a[i + u - 1][j + v - 1] > a[i][j + v - 1] + a[i + u - 1][j]) return false;
    
        return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    int res = 0;
    FOR(u, 2, m) FOR(v, 2, n) FOR(i, 1, m - u + 1) FOR(j, 1, n - v + 1) 
        if (Check(i, i + u - 1, j, j + v - 1)) res = max(res, u * v);

    cout << res;
    cerr << res << '\n';
    
    return 0;
}