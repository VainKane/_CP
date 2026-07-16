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
#define name "489A"

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

int const N = 3009;

int n;
int a[N];

void GenTest()
{
    ofstream cout(name".inp");

    n = Rand(1, 1000);
    FOR(i, 1, n) a[i] = Rand(1, 400);

    cout << n << '\n';
    FOR(i, 1, n) cout << a[i] << ' ';
}

void CheckResult()
{
    ifstream cin(name".out");

    int k;
    cin >> k;

    if (k > n)
    {
        cout << "AHH, too many op bro!\n";
        exit(0);
    }

    FOR(i, 1, k)
    {
        int u, v;
        cin >> u >> v;
        swap(a[u + 1], a[v + 1]);
    }

    FOR(i, 1, n - 1) if (a[i] > a[i + 1])
    {
        cout << "The array is not sorted yet bro!\n";
        FOR(j, 1, n) cout << a[j] << ' ';
        exit(0);
    }
}

int main()
{
    FOR(i, 1, ntest)
    {
        GenTest();
        system(name".exe <"name".inp> "name".out");
        CheckResult();

        cout << "Test: " << i << " CORRECT!\n";
    }

    return 0;
}