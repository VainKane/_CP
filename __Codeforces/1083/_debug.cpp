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
#define name "1083E"

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

    int const lim = 1e4;
    int const oo = 1e9;

    int n = Rand(1, lim);
    vector<int> x(n), y(n);

    REP(i, n) x[i] = Rand(1, oo), y[i] = Rand(1, oo);

    sort(all(x)), sort(all(y));

    x.erase(unique(all(x)), x.end());  
    y.erase(unique(all(y)), y.end());
    
    sort(all(y), greater<int> ());
    n = min(sz(x), sz(y));

    vector<int> id(n);
    REP(i, n) id[i] = i;

    shuffle(all(id), mt19937_64(time(0)));

    cout << n << '\n';
    for (auto &i : id) cout << x[i] << ' ' << y[i] << ' ' << Rand(0, 1LL * x[i] * y[i]) << '\n';
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