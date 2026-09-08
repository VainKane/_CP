#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define name "hexagon"

int const N = 209;
int const X = 100;

int m;
int a[N][N][N];
long long dp[N][N][N];

int dq[3] = {1, -1, 0};
int dr[3] = {0, 1, 1};
int ds[3] = {-1, 0, -1};

bool Inside(int q, int r, int s)
{
    return (abs(q - X) <= m && abs(r - X) <= m && abs(s - X) <= m);
}

int stS[N], stQ[N];
int edS[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> m;
    FOR(i, 1, 1 + 3 * m * (m + 1))
    {
        int q, r, s, val;
        cin >> q >> r >> s >> val;
        a[q + X][r + X][s + X] = val;
    }

    FOR(r, -m, 0) 
    {
        stS[r + X] = m + X;
        edS[r + X] = -r - m + X;
    
        stQ[r + X] = -m - r + X;
    }
    FOR(r, 1, m) 
    {
        stS[r + X] = m - r + X;
        edS[r + X] = -m + X;

        stQ[r + X] = -m + X;
    }
    
    // FOR(r, -m, m) cout << r << ' ' << stS[r + X] - X << ' ' << edS[r + X] - X << ' ' << stQ[r + X] - X << '\n';

    dp[X][-m + X][m + X] = a[X][-m + X][m + X];

    FOR(r, -m + X, m + X) FORD(s, stS[r], edS[r])
    {
        int q = stQ[r] + stS[r] - s;

        REP(i, 3) 
        {
            int q2 = q + dq[i];
            int r2 = r + dr[i];
            int s2 = s + ds[i];

            if (!Inside(q2, r2, s2)) continue;

            dp[q2][r2][s2] = max(dp[q2][r2][s2], dp[q][r][s] + a[q2][r2][s2]);
        }

        // cout << q - X << ' ' << r - X << ' ' << s - X << ' '  << dp[q][r][s] << '\n';
    }

    int x, y, z;
    cin >> x >> y >> z;
    
    cout << dp[x + X][y + X][z + X];

    return 0;
}