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
#define name "1580C"

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

    int const oo = 400;
    int const lim = 5000;

    int n = Rand(1, lim);
    int q = Rand(1, lim);

    bool used[n + 1];
    memset(used, false, sizeof used);

    cout << n << ' ' << q << '\n';
    FOR(i, 1, n) cout << Rand(1, oo) << ' ' << Rand(1, oo) << '\n';
    FOR(i, 1, q)
    {
        vector<int> v1, v2;
        FOR(i, 1, n) 
        {
            if (used[i]) v1.push_back(i);
            else v2.push_back(i);
        }

        int k = Rand(1, 2);
        if (sz(v1) == n) k = 2;
        if (sz(v2) == n) k = 1;

        int id;

        if (k == 1) id = v2[Rand(0, sz(v2) - 1)];
        else id = v1[Rand(0, sz(v1) - 1)];

        used[id] ^= 1;

        cout << k << ' ' << id << '\n';
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