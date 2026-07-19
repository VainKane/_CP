#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define name "PUSHUPS"

int const N = 5009;

int n, m;
int a[N];
bool dp[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m;
    FOR(i, 1, m) cin >> a[i];

    dp[0][0] = true;

    FOR(i, 0, n) FOR(s, 0, 5000) 
    {
        bool processing = false;

        if (dp[i][s]) FOR(j, 1, m)
        {
            int x = i + s + a[j];
            if (x > n) continue;
            
            dp[x][s + a[j]] = true;
            processing = true;
        }

        if (!processing && dp[i][s]) break;
    }

    FORD(s, 5000, 0) if (dp[n][s])
    {
        cout << s;
        return 0;
    }
    
    cout << -1;

    return 0;
}