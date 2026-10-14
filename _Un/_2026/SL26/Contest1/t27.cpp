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

int const N = 2e5 + 5;

int n;
int a[N], b[N];

set<ii> s;
int mx;

void Add(int l, int r)
{
    if (s.empty())
    {
        maxi(mx, r - l);
        s.insert({l, r});
        return;
    }

    auto it = s.lower_bound({l, 0});
    while (it != s.end() && it->F <= r)
    {
        maxi(r, it->S);
        s.erase(it);
        it = s.lower_bound({l, 0});
    }

    it = s.upper_bound({l, 0});
    if (it == s.begin())
    {
        maxi(mx, r - l);
        s.insert({l, r});
        return;
    }

    it--;
    if (it->S < l)
    {
        maxi(mx, r - l);
        s.insert({l, r});
        return;
    }

    l = it->F;
    maxi(mx, r - l);
    s.insert({l, r});
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n;
        FOR(i, 1, n) cin >> a[i];
        FOR(i, 1, n) cin >> b[i];

        ll res = mx = 0;
        s.clear();

        FOR(i, 1, n)
        {
            res += a[i] - b[i];
            Add(b[i], a[i]);

            cout << res - mx << ' ';
        }

        cout << '\n';
    }

    return 0;
}