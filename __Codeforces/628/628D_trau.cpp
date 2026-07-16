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

int m, d, a, b;

bool Check(int x)
{
    if (x % m) return false;
    
    vector<int> digit;
    int n = 0;
    
    while (x)
    {
        digit.push_back(x % 10);

        x /= 10;
        n++;
    }

    reverse(all(digit));

    REP(i, n)
    {
        if (i & 1)
        {
            if (digit[i] != d) return false;
        }
        else if (digit[i] == d) return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> d;
    cin >> a >> b;

    int res = 0;
    FOR(i, a, b) res += Check(i);
    cout << res;

    return 0;
}