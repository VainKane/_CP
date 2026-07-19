#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define sz(v) ((int)v.size())
#define F first
#define S second
#define name "bstr"

int const N = 1e5 + 5;

int n;
char s1[N], s2[N];

vector<int> v01, v10;
vector<pair<int, int>> res;

void Change(vector<int> &v, vector<int> &other)
{
    other.push_back(v.back());
    res.push_back({v.back(), v.back()});
    v.pop_back();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    int cnt = 0;
    
    cin >> n;
    FOR(i, 1, n) cin >> s1[i];
    FOR(i, 1, n)
    {
        cin >> s2[i];
        if (s1[i] != s2[i])
        {
            if (s1[i] == '0') v01.push_back(i);
            else v10.push_back(i);
        }
    }

    if ((sz(v10) + sz(v01)) & 1) 
    {
        cout << -1;
        return 0;
    }

    if (sz(v10) & 1) Change(v10, v01);
    if (sz(v01) & 1) Change(v01, v10);
    
    for (int i = 0; i < sz(v01); i += 2) res.push_back({v01[i], v01[i + 1]});
    for (int i = 0; i < sz(v10); i += 2) res.push_back({v10[i], v10[i + 1]});

    cout << sz(res) << '\n';
    for (auto &p : res) cout << p.F << ' ' << p.S << '\n';

    return 0;
}