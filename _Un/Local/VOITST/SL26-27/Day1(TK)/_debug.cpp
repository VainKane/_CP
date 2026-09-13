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
#define name "COW"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

mt19937_64 rd(time(0));
ll Rand(ll l, ll r) { return l + rd() * 1LL * rd() % (r - l + 1); }

int const ntest = 1;

void GenTest()
{
    ofstream cout(name".inp");

    int const lim = 8000;
    int n = Rand(7500, lim);

    cout << n << '\n';
    FOR(i, 1, n) cout << Rand(1, n) << ' ';
    cout << '\n';
    FOR(i, 1, n) cout << Rand(1, n) << ' ';
}

int main()
{
    FOR(i, 14, 20)
    {
        GenTest();
        system("./"name".exe");

        system(("mkdir test" + to_string(i)).c_str());
        system(("mv "name".inp test" + to_string(i)).c_str());
        system(("mv "name".out test" + to_string(i)).c_str());

        // system("./"name"_brute.exe <"name".inp> "name".ans");

        // if (system("diff "name".out "name".ans") != 0)
        // {
        //     cout << "Test: " << i <<x " WRONG!\n";
        //     return 0;
        // }

        cout << "Test: " << i << " CORRECT!\n";
    }

    return 0;
}