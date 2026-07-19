#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 209;
int const oo = 1e9;

int n, k;
int a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];

    int res = -oo;

    FOR(l, 1, n) FOR(r, l, n)
    {
        int s = 0;
        vector<int> a1, a2;
        FOR(i, l, r) a1.push_back(a[i]), s += a[i];
        FOR(i, 1, l - 1) a2.push_back(a[i]);
        FOR(i, r + 1, n) a2.push_back(a[i]);

        sort(all(a1));
        sort(all(a2), greater<int> ());

        FOR(top, 0, min({sz(a1), sz(a2), k}))
        {
            int s1 = 0, s2 = 0;
            REP(i, top) s1 += a1[i];
            REP(i, top) s2 += a2[i];

            maxi(res, s + s2 - s1);
        }
    }    

    cout << res;

    return 0;
}