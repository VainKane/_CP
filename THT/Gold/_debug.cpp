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
#define name "A"

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

int n, k, s;

void GenTest()
{
    ofstream cout(name".inp");

    int const lim = 10;
    k = 2;
    n = Rand(5, lim);
    s = Rand(1, n * (n + 1) / 2 - 4);

    cout << n << " 2 " << s;
}

void CheckRes()
{
    ifstream cin(name".out");
    FOR(i, 1, k)
    {
        int x, sum = 0;

        while (cin >> x)
        {
            if (x == 0) break;
            if (x < 1 || x > n)
            {
                cout << "Invalid number: " << x << '\n';
                exit(0);
            }
            sum += x;
        }

        if (sum != s)
        {
            cout << "Incorrect sum: " << sum << '\n';
            exit(0);
        }
        cout << "Seq " << i << " Good\n";
    }

    cout << "Test passed!\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    FOR(i, 1, ntest)
    {
        GenTest();
        system(name".exe <"name".inp> "name".out");
        CheckRes();
    }

    return 0;
}
