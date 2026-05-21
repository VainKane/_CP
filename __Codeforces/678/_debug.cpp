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
#define name "B"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

mt19937_64 rd(time(0));
int const ntest = 1e4;

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int const lim = 1e5;
    int const oo = 1e9;

    int n = Rand(1, lim);

    set<int> ids;

    cout << n << '\n';
    FOR(i, 1, n)
    {
        int t = Rand(1, 3);
        if (t == 2 && ids.empty()) t = 1;

        cout << t << ' ';

        if (t == 1)
        {
            cout << Rand(-oo, oo) << ' ' << Rand(-oo, oo) << '\n';
            ids.insert(i);
        }
        else if (t == 2)
        {
            int haha = Rand(1, *ids.rbegin());
            auto it = ids.lower_bound(haha);

            assert(it != ids.end());
            cout << *it << '\n';

            ids.erase(it);
        }
        else cout << Rand(-oo, oo) << '\n';
    }
}

int main()
{
    FOR(i, 1, ntest)
    {
        GenTest();
        system(name".exe <"name".inp> "name".out");
        system(name"_trau.exe <"name".inp> "name".ans");

        if (system("fc "name".out "name".ans") != 0)
        {
            cout << "Test: " << i << " WRONG!\n";
            return 0;
        }

        cout << "Test: " << i << " CORRECT!\n";
    }

    return 0;
}