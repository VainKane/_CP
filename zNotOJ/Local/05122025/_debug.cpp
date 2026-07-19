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
#define name "LUOIDIEN"

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

    int lim = 100;
    int oo = 1e3;

    int n = Rand(1, lim);
    int m = Rand(1, min(n, 17));
    int q = Rand(1, 1);

    int a[n + 1];
    FOR(i, 1, n) a[i] = i;
    random_shuffle(a + 1, a + n + 1);

    cout << n << ' ' << m << ' ' << q << '\n';
    FOR(i, 1, m) cout << a[i] << ' ';
    cout << '\n';

    FOR(i, 1, n)
    {
        FOR(j, 1, n)
        {
            int x = Rand(1, oo);
            if (i == j) x = 0;
            cout << x << ' ';
        }
        cout << '\n';
    }

    FOR(i, 1, q) cout << Rand(1, n) << ' ' << Rand(1, n) << '\n';
}

int main()
{
    FOR(i, 1, ntest)
    {
        GenTest();
        system(name".exe");
        system(name"_trau.exe");

        if (system("fc "name".out "name".ans") != 0)
        {
            cout << "Test: " << i << " WRONG!\n";
            return 0;
        }

        cout << "Test: " << i << " CORRECT!\n";
    }

    return 0;
}