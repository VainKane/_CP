#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define F first
#define S second

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 1e5 + 5;

int n, m;
pair<int, int> a[N];
int b[N];

int l = 0;
int r = 0;

int Update(int x)
{
    FOR(i, 1, )
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i].F >> a[i].S;
    cin >> m;
    FOR(i, 1, m) cin >> b[i];

    FOR(i, 1, m) if (b[i] > r || b[i] < l)
    {

    }

    return 0;
}