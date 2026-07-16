#include <bits/stdc++.h>

using namespace std;

int const N = 30000 * 30 + 10;

int child[N][30];
int pos[N];
int exist[N];
int cost[N];

int cnt = 0;

int n;
int q;
string str;

void Add(string &s, int &ind)
{
    int u = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int k = s[i] - 'a';
        if (!child[u][k]) child[u][k] = ++cnt;
        u = child[u][k];
        cost[ind] += exist[u];
        exist[u]++;
    }
    cost[ind] += ind + s.size();
    if (pos[u] == 0) pos[u] = ind;
}

int Query(string &s)
{
    int u = 0;
    int res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int k = s[i] - 'a';
        if (!child[u][k]) break;
        u = child[u][k];
        res += exist[u];
        if (pos[u] && i == s.size() - 1) return cost[pos[u]];
    }

    return res + n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("14D.inp", "r", stdin);
    // freopen("14D.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> str;
        Add(str, i);
    }

    cin >> q;

    while (q--)
    {
        cin >> str;
        cout << Query(str) << '\n';
    }

    return 0;
}