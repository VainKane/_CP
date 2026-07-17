#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())

int n;
vector<int> a;
vector<int> res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) 
    {
        int x; cin >> x;
        a.push_back(x);
    }

    if (sz(a) == 1) 
    {
        cout << a[0];
        return 0;
    }

    sort(all(a));

    if (n & 1)
    {
        int med = n / 2;
        int x = med;

        if (((a[med] + a[med - 1]) & 1) == 0) x = med + 1;
        else if (((a[med] + a[med + 1]) & 1) == 0) x = med - 1;

        res.push_back(a[x]);
        vector<int> tmp;
        REP(i, n) if (i != x) tmp.push_back(a[i]);
        a = tmp;
        n--;
    }

    int med = n / 2;
    if ((a[med] + a[med - 1]) & 1) cout << -1;
    else
    {
        REP(i, med)
        {
            res.push_back(a[i]);
            res.push_back(a[n - i - 1]);
        }

        reverse(all(res));
        for (auto &x : res) cout << x << ' ';
    }

    return 0;
}
