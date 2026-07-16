#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define F first
#define S second

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 1e6 + 5;

int n;
int a[N];

pair<int, int> res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    int ma = 0;
    FOR(i, 1, n) FOR(j, i + 1, n) if (maxi(ma, __gcd(a[i], a[j]))) res = {i, j};
    cout << res.F << ' ' << res.S;

    return 0;
}