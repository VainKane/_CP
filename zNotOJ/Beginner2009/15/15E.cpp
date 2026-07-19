#include <bits/stdc++.h>

using namespace std;

int const mod = 1e9 + 7;
int const N = 1e5 + 10;

int n;
int dp[N];
string s[(int)1e4 + 10];
string x;

int child[N * 10][30];
bool isEnd[N * 10];
int cnt = 1;

void Add(string &s)
{
    int u = 1;
    for (int i = 0; i < s.size(); i++)
    {
        int k = s[i] - 'a';
        if (!child[u][k]) child[u][k] = ++cnt;
        u = child[u][k];
    }
    isEnd[u] = true;
}

void Query(int &l)
{
    int u = 1;
    int res = 0;

    for (int i = l; i < x.size(); i++)
    {
        int k = x[i] - 'a';
        if (!child[u][k]) return;
        u = child[u][k];
        
        if (isEnd[u])
        {
            dp[i + 1] += dp[l];
            dp[i + 1] %= mod;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        Add(s[i]);
    }

    cin >> x;

    memset(dp, 0, sizeof dp);

    dp[0] = 1;

    for (int i = 0; i < x.size(); i++)
    {
        if (dp[i] > 0) Query(i);
    }

    cout << dp[x.size()];

    return 0;
}