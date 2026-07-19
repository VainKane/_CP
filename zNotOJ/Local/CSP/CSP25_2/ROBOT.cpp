#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define F first
#define S second

int const N = 5009;

int n, m;
int a[N];
pair<int, int> b[N];

long long s[N][N];
long long f[N][N], g[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, m) cin >> b[i].F >> b[i].S;

    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);

    FOR(i, 1, m) FOR(j, 1, n) s[i][j] = s[i][j - 1] + abs(b[i].F - a[j]);

    memset(f, -1, sizeof f);
    f[0][0] = 0;

    FOR(i, 1, m) 
    {
        deque<int> q;
        FOR(j, 0, n)
        {
            while (!q.empty() && q.front() < j - b[i].S) q.pop_front();
            if (f[i - 1][j] != -1)
            {
                while (!q.empty() && g[i - 1][q.front()] > g[i - 1][j]) q.pop_back();
                q.push_back(j);
            }

            if (q.empty()) continue;

            f[i][j] = g[i - 1][q.front()] + s[i][j];
            g[i][j] = f[i][j] - s[i + 1][j];            
        }
    }

    cout << f[m][n];

    return 0;
}