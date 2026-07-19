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

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

struct Dist
{
    long long l, r;
    int id;

    bool operator < (Dist const other) const
    {
        if (r == other.r) return l < other.l;
        return r < other.r;
    }
};

int const N = 2e5 + 5;

int n, m;

Dist p[N];
set<pair<long long, int>> s;

int res[N];

void PrintNo()
{
    cout << "No\n";
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, n) cin >> p[i].l >> p[i].r;
    FOR(i, 1, m)
    {
        long long x; cin >> x;
        s.insert({x, i});
    }

    FOR(i, 1, n - 1)
    {
        long long l1 = p[i].l, r1 = p[i].r;
        long long l2 = p[i + 1].l, r2 = p[i + 1].r;

        p[i].l = l2 - r1;
        p[i].r = r2 - l1;
        p[i].id = i;
    }

    sort(p + 1, p + n);

    FOR(i, 1, n - 1)
    {
        if (s.empty()) PrintNo();
        auto it = s.lower_bound(make_pair(p[i].l, 0));

        if (it == s.end() || (*it).F > p[i].r) PrintNo();
        
        res[p[i].id] = (*it).S;
        s.erase(it);
    }

    cout << "Yes\n";
    FOR(i, 1, n - 1) cout << res[i] << ' ';

    return 0;
}