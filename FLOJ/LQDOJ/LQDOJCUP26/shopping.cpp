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
#define name "shopping"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

string s;

int Get()
{
    REP(i, sz(s) - 1) if (s[i] < s[i + 1]) return i;
    return sz(s);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    int q; cin >> q;
    while (q--)
    {
        cin >> s;

        int idx = Get();
        REP(i, sz(s))
        {
            if (i < idx) cout << s[i];
            else if (i > idx) cout << 0;
            else cout << (char)(s[i] + 1);
        }

        cout << ' ';
    }

    return 0;
}