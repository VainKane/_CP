#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define name "CAU2"

int const N = 3e5 + 5;

int n, m;
vector<string> str[N];

bool Check(string &s)
{
    int m = s.size();
    for (auto &s1 : str[m]) 
    {
        int cnt = 0;
        REP(i, m) if (s1[i] != s[i]) 
        {
            cnt++;
            if (cnt == 2) break;
        }

        if (cnt == 1) return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n >> m;
    FOR(i, 1, n) 
    {
        string s; cin >> s;
        str[s.size()].push_back(s);
    }

    while (m--)
    {
        string s; cin >> s;
        cout << (Check(s) ? "YES\n" : "NO\n");
    }

    return 0;
}