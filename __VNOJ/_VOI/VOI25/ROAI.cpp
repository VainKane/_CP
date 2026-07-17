#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1LL << (i))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second
#define name "ROAI"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 5009;

int n, k;

vector<int> a = {0};
int d[N];

pair<int, int> GetSegments(int x, int l, int r)
{
    return {2 * l - x, 2 * r - x};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> k;
    FOR(i, 1, k)
    {
        int x1, x2;
        cin >> x1 >> x2;

        a.push_back(x1);
        a.push_back(x2);
    }

    a.push_back(n);

    int res = 0;

    REP(x1, n) FOR(x2, x1 + 1, n)
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < sz(a) - 1; i += 2) if (a[i] != a[i + 1])
        {
            auto p1 = GetSegments(x1, a[i], a[i + 1]);
            auto p2 = GetSegments(x2, a[i], a[i + 1]);

            v.push_back(p1);
            v.push_back(p2);
        }

        sort(all(v));
        int haha = v[0].F;

        int tmp = 0;

        for (auto &p : v)
        {
            tmp += max(0, p.S - max(haha, p.F));
            haha = p.S;
        }

        maxi(res, tmp);
    }

    cout << res;

    return 0;
}
