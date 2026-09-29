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

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 1e5 + 5;

int n;
int a[N];

int d[N];

bool Check(int k)
{
    memset(d, 0, sizeof d);
    int cur = 0;

    FOR(i, 1, n)
    {
        cur += d[i];
        if (cur > a[i]) return false;

        if (i > n - k + 1)
        {
            if (cur != a[i]) return false;
            continue;
        }

        d[i + k] -= a[i] - cur;
        cur = a[i];
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    ll s = 0;
    FOR(i, 1, n) s += a[i];

    FORD(i, n, 1) if (s % i == 0 && Check(i))
    {
        cout << i;
        break;
    }

    return 0;
}