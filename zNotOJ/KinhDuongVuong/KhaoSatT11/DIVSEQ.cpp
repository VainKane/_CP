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
#define name "DIVSEQ"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1e6 + 5;

int n, q;
int a[N];

int rb[N];
multiset<int> s;

bool Check(int x)
{
    auto it = lower_bound(all(s), x);
    if (it != s.end() && *it % x != 0) return false;
    
    if (it == s.begin()) return true;
    it--;
    return x % *it == 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];

    int j = 0;
    FOR(i, 1, n)
    {
        while (j < n && Check(a[j + 1])) s.insert(a[++j]);
        rb[i] = j;
        s.erase(s.find(a[i]));
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        cout << (rb[l] >= r ? "YES\n" : "NO\n");
    }

    return 0;
}