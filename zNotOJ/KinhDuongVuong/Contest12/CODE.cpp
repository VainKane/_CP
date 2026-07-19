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

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1e5 + 5;

int n, q;
char a[N][4];

int d[N];

bool cmp(string s1, string s2)
{
    REP(i, sz(s1)) if (s1[i] != s2[i]) return s1[i] < s2[i];
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(k, 1, 3) FOR(i, 1, n) cin >> a[i][k];

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        string s[4];

        FOR(k, 1, 3) FOR(i, l, r) s[k].push_back(a[i][k]);
        sort(s + 1, s + 4, cmp);

        FOR(k, 1, 3) FOR(i, 0, r - l) a[l + i][k] = s[k][i];
    }

    FOR(k, 1, 3)
    {
        FOR(i, 1, n) cout << a[i][k];
        cout << '\n';
    }

    return 0;
}