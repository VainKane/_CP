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
#define name "SHIP"

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
    return l + rd() * 1LL * rd() % (r - l + 1);
}

int const ntest = 1e4;

void GenTest()
{
    ofstream cout(name".inp");

    int oo = 1e9;

    int n = Rand(1, 1e2);
    int k = Rand(1, 2e5);

    int a[n + 1];
    FOR(i, 1, n) a[i] = i;
    random_shuffle(a + 1, a + n + 1);

    cout << n << '\n';
    FOR(i, 1, n) cout << Rand(1, oo) << ' ';
    cout << '\n';
    FOR(i, 2, n) cout << a[i] << ' ' << a[Rand(1, i - 1)] << '\n';
    cout << k << '\n';
    while (k--) cout << Rand(1, n) << ' ' << Rand(1, n) << '\n';
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
