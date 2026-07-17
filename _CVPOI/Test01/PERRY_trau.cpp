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

int const N = 6007;

int n, q;
long long preL[N], preR[N];

int pre[N][N];

bool Check(int l, int r)
{
    return preR[r] - preR[l - 1] >= preL[l - 1] + preL[n] - preL[r];
}

int Get(int top, int bot, int left, int right)
{
    if (top > bot || left > right) return 0;
    return pre[bot][right] - pre[top - 1][right] - pre[bot][left - 1] + pre[top - 1][left - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n)
    {
        int l, r;
        cin >> l >> r;
        preL[i] = preL[i - 1] + l;
        preR[i] = preR[i - 1] + r;
    }

    FOR(l, 1, n) FOR(r, l, n) pre[l][r] = Check(l, r);
    FOR(i, 1, n) FOR(j, 1, n) pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];

    while (q--)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        cout << Get(l1, l2, r1, r2) << '\n';
    }

    return 0;
}