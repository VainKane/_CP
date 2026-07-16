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

int const N = 1e6 + 5;

int n, m, dx, dy;

int yp[N];
int cnt[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> dx >> dy;

    REP(i, n) yp[1LL * dx * i % n] = 1LL * dy * i % n;
    while (m--)
    {
        int x, y;
        cin >> x >> y;

        cnt[(y - yp[x] + n) % n]++;
    }

    int ma = 0;
    int pos;

    REP(i, n) if (maxi(ma, cnt[i])) pos = i;
    cout << "0 " << pos;

    return 0;
}