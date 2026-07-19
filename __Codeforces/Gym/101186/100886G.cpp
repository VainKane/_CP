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

long long a, b;

vector<int> GetDigits(long long x)
{
    vector<int> res;

    while (x)
    {
        res.push_back(x % 10);
        x /= 10;
    }

    reverse(all(res));
    return res;
}

long long GetP(long long x)
{
    long long res = 1;

    while (x)
    {
        res *= x % 10;
        x /= 10;
    }

    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> a >> b;

    vector<int> digits = GetDigits(b);
    int n = sz(digits);

    long long tmp = 0;
    long long res = b;
    long long ma = -1;

    REP(i, n - 1)
    {
        if (digits[i] > 1 || !i)
        {
            unsigned long long num = tmp * 10 + digits[i] - 1;
            while (num * 10 + 9 < b) num = num * 10 + 9;

            if (num >= a && maxi(ma, GetP(num))) res = num;
        }

        tmp = tmp * 10 + digits[i];
    }

    cout << res;

    return 0;
}