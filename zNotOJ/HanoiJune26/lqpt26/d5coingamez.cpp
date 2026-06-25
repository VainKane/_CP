#ifndef LOCALONLY
#include "coingamelib.h"
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
#define name ""

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

#ifdef LOCALONLY

struct Jury
{
    void Judge()
    {
    }
};

void take(int p)
{
    cout << "took: " << p << '\n';
    // haha;
}

#endif // LOCALONLY

int const N = 1e5 + 5;

namespace personA
{
    string send(string w) { return w; }
}

namespace personB
{
    int n;
    bool a[N];

    void Solve(int l, int r)
    {
        bool haha = 0;
        FOR(i, l, r) haha ^= a[i];

        if (haha)
        {
            FOR(i, l, r) if (a[i])
            {
                FORD(j, i, l) take(j);
                a[i + 1] ^= 1;
                return Solve(i + 1, r);
            }
        }
        else FORD(i, r, l) if (a[i])
        {
            FOR(j, i, r) take(j);
            a[i - 1] ^= 1;
            return Solve(l, i - 1);
        }
    }

    void play(string s)
    {
        n = sz(s);
        FOR(i, 1, n) a[i] = s[i - 1] == '0';
        Solve(1, n);
    }
}

#ifdef LOCALONLY
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    personB::play(personA::send("101"));
    // cout << "---------\n";
    // personB::play(personA::send("010"));

    return 0;
}
#endif // LOCALONLY