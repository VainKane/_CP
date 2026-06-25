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

int const N = 1009;
int const M = 1e4 + 1e3 + 5;

struct Data
{
    int w, c, b;

    Data(int _w = 0, int _c = 0, int _b = 0) { w = _w, c = _c, b = _b; }
    void Input() { cin >> w >> c >> b; }
    bool operator < (Data const other) const { return w + c < other.w + other.c; }
};

int n;
Data a[N];
int dp[M];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) a[i].Input();

    sort(a + 1, a + n + 1);
    FOR(i, 1, n) FORD(j, a[i].w + a[i].c, a[i].w) maxi(dp[j], dp[j - a[i].w] + a[i].b);
    cout << *max_element(dp, dp + M);

    return 0;
}