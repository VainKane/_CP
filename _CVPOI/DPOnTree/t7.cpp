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

int const N = 1509;

int n;
char s[N];

int f[26][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> s[i];

    REP(c, 26) 
    {
        FOR(l, 1, n)
        {
            int cnt = 0;
            FOR(r, l, n)
            {
                cnt += s[r] - 'a' != c;
                maxi(f[c][cnt], r - l + 1);
            }
        }

        FOR(i, 1, n) maxi(f[c][i], f[c][i - 1]);
    }

    int q; cin >> q;
    while (q--)
    {
        int x; char c;
        cin >> x >> c;
        cout << f[c - 'a'][min(x, n)] << '\n';
    }

    return 0;
}