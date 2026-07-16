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

int const N = 36;

int n;
int a[N];

bool Check(int mask)
{
    for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
    {
        int i = __builtin_ctz(tmp);
        for (int haha = tmp ^ MK(i); haha; haha ^= haha & -haha)
        {
            int j = __builtin_ctz(haha);
            if (a[i] % a[j] == 0 || a[j] % a[i] == 0) return false;
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    REP(i, n) cin >> a[i];

    int res = 0;
    REP(mask, MK(n)) if (Check(mask)) maxi(res, __builtin_popcount(mask));
    cout << res;

    return 0;
}