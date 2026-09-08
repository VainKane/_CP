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

int const N = 3e5 + 5;

int n, k, t;
vector<ii> a;

int cnt[N];
int cur = 0;

void Update(int val, int delta)
{
    cnt[val] += delta;
    cur += cnt[val] == 1 && delta == 1;
    cur -= cnt[val] == 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k >> t;
    FOR(i, 1, n)
    {
        int m; cin >> m;
        while (m--)
        {
            int x; cin >> x;
            a.push_back({x, i});
        }
    }

    a.push_back({0, 0});
    a.push_back({t, 0});

    sort(all(a));

    int l = 0, res = 0;
    FOR(r, 1, sz(a) - 1)
    {
        while (l < r - 1 && cur > n - k) Update(a[++l].S, -1);
        if (cur <= n - k) maxi(res, a[r].F - a[l].F);
        Update(a[r].S, 1);
    }

    cout << res;

    return 0;
}