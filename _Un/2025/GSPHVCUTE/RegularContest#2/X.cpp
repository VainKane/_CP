#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define name "chemistry"

int const N = 205;
int const X = 1024;

int t;
int n;
int v[N];

int s = 0;
bool dp[N][X][X];
char res[N];

string str = " PVH";

void Reset()
{
    memset(dp, false, sizeof dp);
    dp[0][0][0] = true;
    s = 0;
}

void Solve()
{
    FOR(i, 1, n) REP(a, X) REP(b, X) if (dp[i - 1][a][b])
    {
        dp[i][a ^ v[i]][b] = true;
        dp[i][a][b ^ v[i]] = true;
        dp[i][a][b] = true;
    }

    int ma = -1;
    int a, b;

    REP(i, X) REP(j, X) if (dp[n][i][j])
    {
        int tmp = i + j + (s ^ i ^ j);
        if (tmp > ma)
        {
            ma = tmp;
            a = i;
            b = j;
        }
    }

    vector<int> groups[4];

    for (int i = n; i; i--)
    {
        if (dp[i - 1][a ^ v[i]][b]) groups[1].push_back(i), a ^= v[i];
        else if (dp[i - 1][a][b ^ v[i]]) groups[2].push_back(i), b ^= v[i];
        else groups[3].push_back(i);
    }

    FOR(i, 1, 3) if (groups[i].empty()) FOR(j, 1, 3) if (groups[j].size() > 1) 
    {
        groups[i].push_back(groups[j].back());
        groups[j].pop_back();
        break;
    }

    FOR(i, 1, 3) for (auto idx : groups[i]) res[idx] = str[i];
    FOR(i, 1, n) cout << res[i];
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> t;
    while (cin >> n)
    {
        if (n == 0) return 0;

        Reset();
        FOR(i, 1, n) cin >> v[i], s ^= v[i];
        Solve();
    } 

    return 0;
}