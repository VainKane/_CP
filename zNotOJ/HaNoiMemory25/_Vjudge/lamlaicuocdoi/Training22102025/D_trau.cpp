#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1ll << (i))
#define sz(v) ((int)v.size())

template <class t> maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 22;

int n;
char s[N];

bool Check(string s)
{
    s += '1';

    int cnt = 0;
    vector<int> v;

    REP(i, sz(s))
    {
        if (s[i] == '0') cnt++;
        else
        {
            v.push_back(cnt);
            cnt = 0;
        }
    }

    if (sz(v) == 1) return false;
    REP(i, sz(v) - 1) if (v[i] != v[i + 1]) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    REP(i, n) cin >> s[i];

    int res = 0;

    REP(mask, MK(n))
    {
        string str = "";
        for (int tmp = mask; tmp; tmp ^= tmp & -tmp) 
        {
            int i = __builtin_ctz(tmp & -tmp);
            str += s[i];
        }
        if (Check(str)) maxi(res, sz(str));
    }

    cout << res;

    return 0;
}