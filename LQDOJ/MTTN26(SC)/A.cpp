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
struct Jury
{
    int x;
    int cnt;

    void Input()
    {
        cin >> x;
        cnt = 0;
    }

    pair<int, double> Query(int h)
    {
        assert(h >= 1 && h <= 1e9);
        assert(++cnt <= 25);

        if (h == x) return {1, 0};
        else return {0, max(0.0, 1 - (double)abs(x - h) / x)};
    }
} jury;
#endif // LOCALONLY

int p, d;

pair<int, double> Query(int h)
{
    #ifdef LOCALONLY
    return jury.Query(h);
    #endif // LOCALONLY

    cout << h << '\n' << flush;
    
    int res; 
    double x = 0;
    
    cin >> res;
    if (res == -1) exit(0);
    if (res == 0) cin >> x;

    return {res, x};
}

void Solve()
{
    int l = 1;
    int r = d;
    int res = r;

    while (l <= r)
    {
        int mid = (l + r) >> 1;
        auto p = Query(2 * mid);

        if (p.F == 1) return;
        if (p.S == 0)
        {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    Query(res);
}

int main()
{
    cin >> p >> d;
    FOR(i, 1, p) 
    {
        #ifdef LOCALONLY
        jury.Input();
        #endif // LOCALONLY
        Solve();
    }

    return 0;
}