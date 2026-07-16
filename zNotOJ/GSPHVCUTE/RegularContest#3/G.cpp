#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)         
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)      
#define name "saudi"      

int const N = 4e5 + 5;

int n;
string s;

vector<int> bd[4];
int res[N];

int Dir(char ch)
{
    if (ch == 'N') return 0;
    if (ch == 'E') return 1;
    if (ch == 'S') return 2;
    return 3;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> s;

    REP(k, 4) bd[k].push_back(1);
    FOR(i, 2, n) 
    {
        int k = Dir(s[i - 2]);

        set<int> lands;

        for (auto j : bd[k]) lands.insert(j);
        for (auto j : bd[(k + 1) % 4]) lands.insert(j);

        for (auto j : lands) res[i]++, res[j]++;

        bd[k] = bd[(k + 1) % 4] = {i};
        bd[(k + 2) % 4].push_back(i);
        bd[(k + 3) % 4].push_back(i);
    }

    FOR(i, 1, n) cout << res[i] << ' ';

    return 0;
}