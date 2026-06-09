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

int const N = 1e4 + 5;

int n;
bool mark[N];

bool Query(int u, int v)
{
    cout << "? " << u << ' ' << v << '\n' << flush;
    string s; cin >> s;
    return sz(s) == 5;
}

bool Check(int u)
{
    FOR(v, 1, n) if (v != u)
    {
        if (Query(v, u)) return false;
        if (!Query(u, v)) return false;
    }
    return true;
}

void Answer()
{
    FOR(u, 1, n) if (!mark[u] && Check(u))
    {
        cout << "! " << u << '\n' << flush;
        return;
    }

    cout << "! FRIENDLY\n" << flush;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n;
        memset(mark, false, (n + 1) * sizeof(bool));

        FOR(u, 1, n) FOR(v, 1, n) if (v != u && !mark[u] && !mark[v])
        {
            if (Query(u, v)) mark[v] = true;
            else mark[u] = true;
        }

        Answer();
    }

    return 0;
}