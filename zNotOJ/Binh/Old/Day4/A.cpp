#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 309;
int const oo = 1e9;

int n, m;
string s, t;

vector<int> pos[30];

int dp[N][N];

void Init()
{
    s = " " + s;
    t = " " + t;

    FOR(i, 1, n) pos[s[i] - 'a'].push_back(i);

    memset(dp, 0x3f, sizeof dp);
    for (auto &v : pos[t[1] - 'a']) dp[1][v] = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    cin >> s >> t;

    Init();

    FOR(i, 2, m) 
    {
        char ch = t[i] - 'a';

        for (auto &u : pos[ch])
            dp[i][u] = min(dp[i - 1][u - 1], dp[i - 1][u + 1]) + 1;
        
        for (auto &u : pos[ch]) for (auto &v : pos[ch]) 
            mini(dp[i][u], dp[i][v] + abs(u - v));
    }

    int res = *min_element(dp[m] + 1, dp[m] + n + 1);
    if (res > oo) res = -1;

    cout << res;

    return 0;
}