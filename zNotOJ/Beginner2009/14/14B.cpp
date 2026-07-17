#include <bits/stdc++.h>

using namespace std;

int child[(int)1e6 + 10][30];
int exist[(int)1e6 + 10];

int cnt = 0;

int n;
string str;

void Add(string &s)
{
    int u = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int k = s[i] - 'a';
        if (!child[u][k]) child[u][k] = ++cnt;
        u = child[u][k];
        exist[u]++;
    }
}

int Query(string &s)
{
    int u = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int k = s[i] - 'a';
        if (!child[u][k]) return 0;
        u = child[u][k];
    }
    return exist[u];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    while (n--)
    {
        cin >> str;
        Add(str);
    }

    cin >> n;
    while (n--)
    {
        cin >> str;
        cout << Query(str) << '\n';
    }

    return 0;
}