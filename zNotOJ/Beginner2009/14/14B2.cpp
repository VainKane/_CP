#include <bits/stdc++.h>

using namespace std;

int n;

int child[(int)1e7 + 10][30];
int exist[(int)2e7 + 10];

int cnt = 0;

int res = 0;

void Add(string &s)
{
    int u = 0;
    int length = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int k = s[i] - 'A';
        if (!child[u][k]) child[u][k] = ++cnt;
        u = child[u][k];
        exist[u]++;

        res = max(res, exist[u] * (++length));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    while (n--)
    {
        string s;
        cin >> s;
        Add(s);
    }

    cout << res;

    return 0;
}