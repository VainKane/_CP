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

string s;
ll k;

namespace Sub1
{
    bool CheckSub()
    {
        return true;
    }

    string Del(string &s)
    {
        string res = "";

        int idx = sz(s) - 1;
        REP(i, sz(s) - 1) if (s[i] > s[i + 1])
        {
            idx = i;
            break;
        }

        REP(i, sz(s)) if (i != idx) res += s[i];
        return s = res;
    }

    char Process()
    {
        string res = " " + s;
        ll len = sz(s);

        REP(haha, sz(s) - 1)
        {
            if (len > k) break;
            res += Del(s);
            len += sz(s);
        }

        return res[k];
    }
}

namespace Sub2
{
    bool CheckSub()
    {
        REP(i, sz(s) - 1) if (s[i] > s[i + 1]) return false;
        return true;
    }

    char Process()
    {
        int len = sz(s);
        while (k > len && len > 1) k -= len--;
        return s[k - 1];
    }
}

char Solve()
{
    if (Sub2::CheckSub()) return Sub2::Process();
    if (Sub1::CheckSub()) return Sub1::Process();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen(name".inp", "r", stdin);
    // freopen(name".out", "w", stdout);

    int t; cin >> t;
    while (t--)
    {
        cin >> s >> k;
        cout << Solve() << '\n';
    }

    return 0;
}