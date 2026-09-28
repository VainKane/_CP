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
#define name "TIME"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 1e6 + 5;

string s;
ll k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    int t; cin >> t;
    while (t--)
    {
        cin >> s >> k;

        int len = sz(s);
        int cnt = 0;
        while (k > len && len > 1) k -= len--, cnt++;

        s += 'a' - 1;

        string st = "";
        int haha = 0;

        REP(i, sz(s))
        {
            while (!st.empty() && s[i] < st.back() && haha < cnt)
            {
                st.pop_back();
                haha++;
            }

            st.push_back(s[i]);
        }

        cout << st[k - 1] << '\n';
    }

    return 0;
}