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
#define name "410"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

mt19937_64 rd(time(0));
ll Rand(ll l, ll r) { return l + rd() * 1LL * rd() % (r - l + 1); }

int const ntest = 1e4;

void GenTest()
{
    ofstream cout(name".inp");

    int const lim = 4;
    int const oo = 3;

    int n = Rand(2, lim);

    cout << n << '\n';

    cout << Rand(2, n) << ' ' << Rand(1, oo) << '\n';
    FOR(i, 2, n - 1)
    {
        int haha[] = {Rand(1, i - 1), Rand(i + 1, n)};
        cout << haha[Rand(0, 1)] << ' ' << Rand(1, oo) << '\n';
    }
    cout << Rand(1, n - 1) << ' ' << Rand(1, oo) << '\n';
}

int main()
{
    FOR(i, 1, ntest)
    {
        GenTest();
        system("./"name".exe <"name".inp> "name".out");
        system("./"name"_brute.exe <"name".inp> "name".ans");

        if (system("diff "name".out "name".ans") != 0)
        {
            cout << "Test: " << i << " WRONG!\n";
            return 0;
        }

        cout << "Test: " << i << " CORRECT!\n";
    }

    return 0;
}