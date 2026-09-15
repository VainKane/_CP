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

int n, k;

int x[N];
bool mark[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n) cin >> x[i];

    set<ii> s, ssuf;
    FOR(i, 1, n) ssuf.insert({x[i], -i});

    FOR(i, 1, n)
    {
        if (!mark[i]) ssuf.erase({x[i], -i});

        ii val = {n + 1, -(n + 1)};
        int op = 0;

        if (!mark[i])
        {
            val = {x[i], -i};
            if (k >= 1 && !s.empty() && mini(val, *s.begin())) op = 1;
            if (k >= 2 && !ssuf.empty() && mini(val, *ssuf.begin())) op = 2;
         
            if (val.F == x[i]) val = {x[i], -i}, op = 0;
        }
        else
        {
            if (!s.empty()) mini(val, *s.begin()), op = 1;
            if (k >= 1 && !ssuf.empty() && mini(val, *ssuf.begin())) op = 2;
        }

        if (op == 1) s.erase(val);
        if (op == 2)
        {
            ssuf.erase(val);
            mark[-val.S] = true;
        }

        if (!mark[i] && op) s.insert({x[i], -i});

        k -= op - mark[i];
        cout << val.F << ' ';
    }

    return 0;
}