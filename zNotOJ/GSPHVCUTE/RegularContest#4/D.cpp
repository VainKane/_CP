#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define name "couples"

int const N = 3e5 + 5;

int n, m;
vector<pair<int, int>> boysShorter, boysTaller;
vector<pair<int, int>> girlsShorter, girlsTaller;

vector<pair<int, int>> res;

void Count(vector<pair<int, int>> &shorter, vector<pair<int, int>> &taller, bool boyToGirl)
{
    sort(all(shorter));
    sort(all(taller));

    int i = 0;
    for (auto &x : shorter)
    {
        if (i == taller.size()) break;

        if (x.F > taller[i].F)
        {
            int boyId = x.S;
            int girlId = taller[i].S;

            if (!boyToGirl) swap(boyId, girlId);
            res.push_back({boyId, girlId});
            i++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    int sub; cin >> sub;
    cin >> n;
    FOR(i, 1, n) 
    {
        int x; cin >> x;
        if (x < 0) boysShorter.push_back({-x, i});
        else boysTaller.push_back({x, i});
    }
    cin >> m;
    FOR(i, 1, m) 
    {
        int x; cin >> x;
        if (x < 0) girlsShorter.push_back({-x, i});
        else girlsTaller.push_back({x, i});
    }

    Count(boysShorter, girlsTaller, true);
    Count(girlsShorter, boysTaller, false);

    cout << res.size() << '\n';
    for (auto p : res) cout << p.F << ' ' << p.S << '\n';

    return 0;
}