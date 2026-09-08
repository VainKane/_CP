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
#define name "KEYBOARD"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1e5 + 5;
int const oo = 1e9;

int n, m;
char s[N];

int cnt[25][25];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m;
    FOR(i, 1, n) cin >> s[i];

    FOR(i, 2, n)
    {
        int a = s[i] - 'a';
        int b = s[i - 1] - 'a';

        if (a > b) swap(a, b);
        cnt[a][b]++;
    }

    vector<int> p;
    REP(i, m) p.push_back(i);

    int res = oo;

    do
    {
        int s = 0;
        REP(i, m) FOR(j, i + 1, m - 1) s += cnt[i][j] * abs(p[i] - p[j]);
        mini(res, s);
    } while (next_permutation(all(p)));

    cout << res;

    return 0;
}