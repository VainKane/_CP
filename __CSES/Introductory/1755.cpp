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

string s;

int cnt[26];

string Solve()
{
    string res = "";
    char hihi = '#';
    
    REP(i, 26)
    {
        if (cnt[i] & 1)
        {
            if (hihi != '#' || !(sz(s) & 1)) return "NO SOLUTION";
            else hihi = 'A' + i;
        }
        res += string(cnt[i] / 2, 'A' + i);
    }

    string tmp = res;
    reverse(all(tmp));
    if (hihi != '#') res += hihi;
    return res + tmp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;
    for (auto &c : s) cnt[c - 'A']++;
    cout << Solve();

    return 0;
}