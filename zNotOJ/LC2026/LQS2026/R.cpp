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

int n, k;
ll pw[6][22];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    FOR(i, 1, 5)
    {
        pw[i][0] = 1;
        FOR(j, 1, 21) pw[i][j] = 1LL * pw[i][j - 1] * i; 
    }

    int t; cin >> t;
    while (t--)
    {
        cin >> n >> k;
        FOR(i, 1, k) cout << 2 * pw[i][n + 1] << ' ' << 2 * pw[i][n + 1] << ' ' << 2 * pw[i][n] << '\n';
    }

    return 0;
}