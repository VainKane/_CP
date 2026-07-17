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

long long l, r;

bool Check(long long x)
{
    vector<int> digits;

    while (x)
    {
        digits.push_back(x % 10);
        x /= 10;
    }

    reverse(all(digits));
    if (sz(digits) < 3) return false;

    bool c4, c8;
    c4 = c8 = false;

    for (auto &d : digits)
    {
        c4 |= (d == 4);
        c8 |= (d == 8);
    }

    if (c4 & c8) return false;

    int cnt = 1;
    int pre = digits[0];

    FOR(i, 1, sz(digits) - 1)
    {
        cnt = digits[i] == pre ? cnt + 1 : 1;
        pre = digits[i];

        if (cnt >= 3) return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> l >> r;

    long long res = 0;
    for (long long i = l; i <= r; i++) res += Check(i);
    cout << res;

    return 0;
}