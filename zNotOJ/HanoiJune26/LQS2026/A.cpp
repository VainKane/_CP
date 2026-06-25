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

int const N = 501;
int const LIM = 500 * 500;

int n, s;
int w[N], v[N];

ll dp[N * N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> s;
    FOR(i, 1, n) cin >> w[i];
    FOR(i, 1, n) cin >> v[i];

    int idx = 0;
    double rad = 0;

    FOR(i, 1, n) if (maxi(rad, 1.0 * v[i] / w[i])) idx = i;

    FOR(i, 1, n) FOR(j, w[i], LIM)
        maxi(dp[j], dp[j - w[i]] + v[i]);
    
    if (s <= LIM) cout << dp[s];
    else
    {
        int k = (s - LIM + w[idx] - 1) / w[idx];
        cout << 1LL * k * v[idx] + dp[s - k * w[idx]];
    }

    return 0;
}