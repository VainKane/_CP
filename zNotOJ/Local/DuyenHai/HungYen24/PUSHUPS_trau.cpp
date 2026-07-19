#include <bits/stdc++.h>
using namespace std;

#define name "PUSHUPS"
#define FOR(i,a,b) for(int i=(a), _b=(b); i<=_b; ++i)

int const N = 5005;

int n, m;
int s[15];
bool f[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n >> m;
    FOR(i,1,m) cin >> s[i];

    f[0][0] = true;

    FOR(u,0,n)
    {
        FOR(v,0,n)
        {
            if (!f[u][v]) continue;
            FOR(i,1,m)
            {
                int new_push = u + v + s[i];
                int new_score = v + s[i];
                if (new_push <= n)
                    f[new_push][new_score] = true;
            }
        }
    }

    for (int x = n; x >= 0; --x)
    {
        if (f[n][x])
        {
            cout << x << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';
}
