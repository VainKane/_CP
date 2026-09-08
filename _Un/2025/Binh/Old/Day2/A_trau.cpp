#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 509;

int m, n, A, B;
int a[N][N];

long long pre[N][N];

long long Get(int top, int bot, int left, int right)
{
    return pre[bot][right] - pre[bot][left - 1] - pre[top - 1][right] + pre[top - 1][left - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("A.inp", "r", stdin);

    cin >> m >> n >> A >> B;
    FOR(i, 1, m) FOR(j, 1, n) 
    {
        cin >> a[i][j];
        pre[i][j] = pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1] + a[i][j];
    }

    long long res = a[1][1];
    FOR(i, 1, m) FOR(j, 1, n) FOR(u, i, m) FOR(v, j, n)
    {
        long long s = Get(i, u, j, v);
        if (abs(s - A) + abs(s - B) < abs(res - A) + abs(res - B)) res = s;
    }

    cout << abs(res - A) + abs(res - B);

    return 0;
}