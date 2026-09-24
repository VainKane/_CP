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
#define name "K"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 1e5 + 5;
ll const oo = 1e18 + 9;

int n;

int x[N], y[N];
int id[N];

ll pre[N];

int Dist(int i, int j) { return abs(x[i] - x[j]) + abs(y[i] - y[j]); }
bool cmp(int i, int j) { return x[i] + y[i] < x[j] + y[j]; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> n;
    FOR(i, 1, n)
    {
        cin >> x[i] >> y[i];
        id[i] = i;
    }

    sort(id + 1, id + n + 1, cmp);
    FOR(i, 2, n) pre[i] = pre[i - 1] + Dist(id[i], id[i - 1]);

    pair<ll, int> res = {oo, 1};
    FOR(i, 1, n - n / 2 + 1) mini(res, {pre[i + n / 2 - 1] - pre[i], i});
    
    FOR(i, res.S, res.S + n / 2 - 1) cout << id[i] << ' ';
    cerr << res.F << ' ' << res.S;

    return 0;
}