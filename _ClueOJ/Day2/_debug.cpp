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
#define name "MESSAGE"

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
int const N = 2e5 + 5;

int a[N];

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int lim = 2e5;
    int oo = 1e9;

    int n = Rand(1, lim);
    int m = Rand(n - 1, 3e5);

    int a[n + 1];
    FOR(i, 1, n) a[i] = i;
    random_shuffle(a + 1, a + n + 1);

    cout << n << ' ' << m << ' ' << Rand(1, n) << ' ' << Rand(1, n) << '\n';
    FOR(i, 2, n) cout << a[i] << ' ' << a[Rand(1, i - 1)] << ' ' << Rand(1, oo) << ' ' << Rand(1, 20) << '\n';
    FOR(i, 1, m - n + 1) cout << Rand(1, n) << ' ' << Rand(1, n) << ' ' << Rand(1, oo) << ' ' << Rand(1, 20) << '\n';
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
