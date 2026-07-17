#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 10;

int child[N * 10][30];
int cnt = 1;

int n;
string a[N];
string str;

int t;

// queris' vars

int m;
int k;
int u;

string res;
string dict[N * 10];

//

int x[15];

void Add(string &s)
{
    int u = 1;
    for (int i = 0; i < s.size(); i++)
    {
        int k = s[i] - 'a';
        if (!child[u][k]) child[u][k] = ++cnt;
        u = child[u][k];
    }
    if (dict[u] == "") dict[u] = str;
    else if (dict[u] > str) dict[u] = str;
}

void Try(int pos)
{
    if (pos > k)
    {
        if (res.size() < dict[u].size())
        {
            res = dict[u];
        }
        if (res.size() == dict[u].size() && res > dict[u])
        {
            res = dict[u];
        }
        return;
    }

    int pre = u;
    for (int i = x[pos - 1] + 1; i <= m - k + pos; i++)
    {
        x[pos] = i;

        int p = str[x[pos]] - 'a';
        if (child[u][p]) 
        {
            u = child[u][p];
        }

        Try(pos + 1);
        u = pre;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("15F.inp", "r", stdin);
    // freopen("15F.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> str;
        string s1 = str;
        sort(s1.begin(), s1.end());
        Add(s1);
    }

    cin >> t;
    while (t--)
    {
        cin >> str;
        sort(str.begin(), str.end());
        str = " " + str;
        m = str.size() - 1;
        k = 1;
        res = "";

        while (k <= m) 
        {
            u = 1;
            Try(1);
            k++;
        }

        if (res == "") res = "IMPOSSIBLE";

        cout << res << '\n';
    }

    return 0;
}