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
#define name "BLACKCELL"

int const ntest = 1e4;

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int lim = 1e2;

    int n = Rand(1, lim);
    int m = Rand(1, lim);
    int q = Rand(1, 1e5);

    cout << "0\n";
    cout << n << ' ' << m << ' ' << q << '\n';
    int cnt = 0;

    FOR(i, 1, q)
    {
        int type = Rand(1, 2);
        if (cnt < 5) type = Rand(1, 3);

        cout << type << ' ';

        if (type == 1)
        {
            int x1 = Rand(1, n);
            int y = Rand(1, m);

            cout << x1 << ' ' << y << ' ' << Rand(x1, n) << ' ' << y << '\n';
        }
        else if (type == 2)
        {
            int x = Rand(1, n);
            int y1 = Rand(1, m);

            cout << x << ' ' << y1 << ' ' << x << ' ' << Rand(y1, m) << '\n';
        }
        else if (type == 3)
        {
            int x1 = Rand(1, n);
            int y1 = Rand(1, m);
            int d = Rand(0, min(n - x1, m - y1));

            cout << x1 << ' ' << y1 << ' ' << x1 + d << ' ' << y1 + d << '\n';
            cnt++;
        }
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
