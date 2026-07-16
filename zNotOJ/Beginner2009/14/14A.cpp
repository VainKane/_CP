#include <bits/stdc++.h>

using namespace std;

int n;
int m;

int cnt = 0;

int child[(int)5e6 + 10][30];
int exist[(int)5e6 + 10];

void Add(string &s)
{
    int u = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int k = s[i] - 'a';
        if (!child[u][k]) child[u][k] = ++cnt;
        u = child[u][k];
    }
    exist[u]++;
}

bool Query(string &s)
{
    int u = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int k = s[i] - 'a';
        if (!child[u][k]) return false;
        u = child[u][k];
    }
    return exist[u];
}

string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    while (n--)
    {
        cin >> s;
        Add(s);
    }

    cin >> m;
    while (m--)
    {
        cin >> s;
        cout << Query(s) << '\n';
    }

    return 0;
}