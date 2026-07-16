#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "SUBSEQ"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 1e6 + 5;
int const oo = 1e9;

int n, k;
int a[N], pre[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i], pre[i] = pre[i - 1] + a[i];

    int res = -oo;
    FOR(i, 1, n) FOR(j, i + k - 1, n) maxi(res, pre[j] - pre[i - 1]);
    cout << res;

    return 0;
}