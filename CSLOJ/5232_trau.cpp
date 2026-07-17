#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())

int n;
vector<pair<int, int>> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        FOR(x, x1 + 1, x2) FOR(y, y1 + 1, y2) v.push_back({x, y});
    }

    sort(all(v));
    v.erase(unique(all(v)), v.end());
    cout << sz(v);

    return 0;
}