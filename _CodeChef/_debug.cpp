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
#define name "NPLFLF"

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

    int const lim = 1000;

    int n = Rand(1, lim);
    vector<int> ids;

    cout << n << '\n';
    FOR(haha, 1, n)
    {
        int type = Rand(1, 3);
        if (type == 3 && ids.empty()) type = 1;
       
        cout << type << ' ';

        if (type == 1)
        {
            int len = Rand(1, 15);
            while (len--) cout << (char)Rand('a', 'd');
            ids.push_back(haha);
        }
        else if (type == 2) cout << Rand(1, min(n, 36)) << ' ' << Rand(1, 10);
        else cout << ids[Rand(0, sz(ids) - 1)];

        cout << '\n';
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