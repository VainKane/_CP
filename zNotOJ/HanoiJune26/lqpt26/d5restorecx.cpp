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

int const N = 509;

int n;
string a[N];
vector<string> s;

bool del[N];

bool Inside(string a, string b)
{
    REP(i, sz(b) - sz(a))
    {
        bool ok = true;
        REP(j, sz(a)) if (a[i] != a[j])
        {
            ok = false;
            break;
        }

        if (ok) return true;
    }
    return false;
}

pair<int, string> Common(string a, string b)
{
    int len = 1;
    for (; len <= min(sz(a), sz(b)) && a[sz(a) - len] == b[len - 1]; len++); len--;

    string res = "";
    REP(i, sz(a) - len) res += a[i];
    return {len, res + b};
}

void Init()
{
    FOR(i, 1, n) FOR(j, i + 1, n) if (!del[j])
    {
        if (Inside(a[i], a[j])) del[i] = true;
        if (Inside(a[j], a[i])) del[j] = true;
    }

    FOR(i, 1, n) if (!del[i]) s.push_back(a[i]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    Init();

    // while (sz(s) > 1)
    // {
    //     pair<int, string> p = {-1, ""};
    //     int x = 0, y = 0;

    //     REP(i, sz(s)) REP(j, sz(s)) if (i != j && maxi(p, Common(s[i], s[j]))) x = i, y = j;

    //     cout << sz(s) << ' ' << x << ' ' << y << ' ' << p.F << ' ' << p.S << '\n';

    //     vector<string> v = {p.S};
    //     REP(i, sz(s)) if (i != x && i != y) v.push_back(s[i]);
    //     s = v;
    // }

    // cout << s[0];

    cout << Common("bba", "abaa").S;

    return 0;
}