#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()
#define F first
#define S second

int m, n;
vector<vector<int>> a;

bool Check(int x)
{
    vector<pair<int, int>> pos;
    FOR(i, 1, m) FOR(j, 1, n) if (a[i][j] < x) pos.push_back({i, j});

    sort(all(pos));

    pair<int, int> last = {0, 0};
    for (auto &p : pos) 
    {
        if (p.F < last.F || p.S < last.S) return false;
        last = p;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> m >> n;
        a.assign(m + 2, vector<int> (n + 2));

        FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

        int l = 0;
        int r = m * n;
        int res = l;

        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (Check(mid))
            {
                res = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }

        cout << res << '\n';
    }


    return 0;
}