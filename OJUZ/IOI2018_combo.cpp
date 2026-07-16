#ifndef LOCALONLY
#include "combo.h"
#endif // LOCALONLY

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

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

#ifdef LOCALONLY

#define name "2742"
string guess_sequence(int);

struct Jury
{
    int n;
    string s;

    int cnt = 0;
    int QueryLim;
    string moves = "ABXY";

    void Input()
    {
        cin >> n >> s;
        QueryLim = 4 * n;
    }

    bool Check(char ch)
    {
        for (auto &x : moves) if (ch == x) return true;
        return false;
    }

    int press(string t)
    {
        assert(++cnt <= QueryLim);
        assert(sz(t) <= 4 * n);
        for (auto &ch : t) assert(Check(ch));

        int res = 0;
        int len = 0;

        REP(i, sz(t))
        {
            if (len < n && s[len] == t[i]) len++;
            else if (s[0] == t[i]) len = 1;
            else len = 0;

            maxi(res, len);
        }

        return res;
    }

    void Judge()
    {
        assert(guess_sequence(n) == s);
    }
} jury;

int press(string t)
{
    return jury.press(t);
}

#endif // LOCALONLY

int n;
string moves = "ABXY";

string guess_sequence(int NN)
{
    n = NN;
    string s = "";

    if (press("AB"))
    {
        if (press("A")) s = "A";
        else s = "B";
    }
    else if (press("X")) s = "X";
    else s = "Y";

    string haha = "";
    for (auto &ch : moves) if (ch != s[0]) haha += ch;

    FOR(i, 1, n - 2)
    {
        int len = press(s + haha[0] + s + haha[1] + haha[0] + s + haha[1] + haha[1] + s + haha[1] + haha[2]);
        if (len == i + 1) s += haha[0];
        else if (len == i + 2) s += haha[1];
        else s += haha[2];
    }

    if (n != 1)
    {
        if (press(s + haha[0]) == n) s += haha[0];
        else if (press(s + haha[1]) == n) s += haha[1];
        else s += haha[2];
    }

    return s;
}

#ifdef LOCALONLY
int main()
{
    freopen(name".inp", "r", stdin);

    jury.Input();
    jury.Judge();

    return 0;
}
#endif // LOCALONLY