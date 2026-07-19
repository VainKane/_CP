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
#define name "BUS"

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

    int const lim = 100;
    
    int n = Rand(2, lim);
    int m = Rand(n - 1, lim);
    int q = Rand(1, lim);

    vector<ii> e;

    FOR(i, 2, n) e.push_back({Rand(1, i - 1), i});
    FOR(i, 1, m)
    {
        int u = Rand(1, n - 1);
        e.push_back({u, Rand(u + 1, n)});
    }

    sort(all(e));
    e.erase(unique(all(e)), e.end());
    shuffle(all(e), rd);

    m = sz(e);

    cout << n << ' ' << m << ' ' << q << '\n';
    for (auto &p : e) cout << p.F << ' ' << p.S << '\n';
    while (q--) cout << Rand(1, n) << '\n';
}

int main()
{
    FOR(i, 1, ntest)
    {
        GenTest();
        system(name".exe <"name".inp> "name".out");
        system(name"_brute.exe <"name".inp> "name".ans");

        if (system("fc "name".out "name".ans") != 0)
        {
            cout << "Test: " << i << " WRONG!\n";
            return 0;
        }

        cout << "Test: " << i << " CORRECT!\n";
    }

    return 0;
}