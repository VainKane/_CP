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

int const N = 109;

int n;
int a[N], id[N];

bool Solve()
{
    FOR(i, 1, n - 1) if (a[i] == a[i + 1]) return false;
    return true;
}

bool cmp(int i, int j)
{
    return a[i] < a[j];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n;
        FOR(i, 1, n) cin >> a[i], id[i] = i;

        sort(id + 1, id + n + 1, cmp);
        FOR(i, 1, n) a[id[i]] = (i & 1);

        cout << (Solve() ? "YES\n" : "NO\n");
    }

    return 0;
}