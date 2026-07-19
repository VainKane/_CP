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
#define name ""

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

string s;
int n, k;

bool Equal(int x, int l, int r)
{
    FOR(i, 0, r - l) if (s[x + i] != s[l + i]) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s >> k;

    n = sz(s);
    s = " " + s;

    int res = 0;
    FOR(i, 1, n - k + 1)
    {
        int cnt = 0;
        FOR(j, 1, n - k + 1) cnt += Equal(i, j, j + k - 1);
        maxi(res, cnt);
    }

    cout << res;

    return 0;
}
