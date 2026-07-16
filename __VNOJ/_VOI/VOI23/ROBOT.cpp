#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1ll << (i))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second
#define name "ROBOT"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const oo = 1e9 + 5;

int w, l, n, q;

namespace Sub1
{
    bool CheckSub()
    {
        return w == 1;
    }

    multiset<int> a, d;

    void AddPoint(int x)
    {
        auto r = lower_bound(all(a), x);
        auto l = upper_bound(all(a), x);
        if (l != a.end()) l--;

        auto it = d.find((*r - *l + 1) / 2);
        if (it != d.end()) d.erase(it);
        if (l != a.end()) d.insert((x - *l + 1) / 2);
        if (r != a.end()) d.insert((*r - x + 1) / 2);
        a.insert(x);
    }

    void RemovePoint(int x)
    {
        a.erase(a.find(x));

        auto r = lower_bound(all(a), x);
        auto l = upper_bound(all(a), x);
        if (l != a.end()) l--;

        if (r != a.end() && l != a.end()) d.insert((*r - *l + 1) / 2);
        if (l != a.end()) 
        {
            auto it = d.find((x - *l + 1) / 2);
            if (it != d.end()) d.erase(it);
        }
        if (r != a.end()) 
        {
            auto it = d.find((*r - x + 1) / 2);
            if (it != d.end()) d.erase(it);
        }
    }

    int Cal()
    {
        int res = sz(d) ? *d.rbegin() : 0;
        return max({res, *a.begin() - 1, l - *a.rbegin()});
    }

    void Solve()
    {
        FOR(i, 1, n)
        {
            int x; cin >> x >> x;
            AddPoint(x);
        }

        cout << Cal() << '\n';

        while (q--)
        {
            int x; cin >> x >> x;

            if (a.count(x) + (x != 1 && x != l) > 1) RemovePoint(x);
            else AddPoint(x);

            cout << Cal() << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> w >> l >> n >> q;

    if (Sub1::CheckSub()) return Sub1::Solve(), 0;

    return 0;
}