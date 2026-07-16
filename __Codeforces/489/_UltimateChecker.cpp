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
#define name "489E"

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
    return l + rd() * 1LL * rd() % (r - l + 1);
}

int const N = 36;

int n, l;
int x[N], b[N];

double res;

void GenTest()
{
    ofstream cout(name".inp");

    n = Rand(1, 3);
    l = Rand(1, 100);

    set<int> s;
    while (sz(s) != n) s.insert(Rand(1, 300));

    int cnt = -1;
    for (auto &val : s) 
    {
        x[++cnt] = val;
        b[cnt] = Rand(1, 300);
    }
    
    cout << n << ' ' << l << '\n';
    REP(i, n) cout << x[i] << ' ' << b[i] << '\n';
}

void GetResult()
{
    ifstream cin(name".ans");
    cin >> res;
}

void CheckResult()
{
    ifstream cin(name".out");

    int last = -1, idx;
    
    double s1 = 0;
    int s2 = 0;

    while (cin >> idx)
    {
        idx--;

        if (last != -1) s1 += sqrt(abs(x[idx] - x[last] - l));
        else s1 += sqrt(abs(x[idx] - l));

        s2 += b[idx];
        last = idx;
    }

    cout << fixed << setprecision(10);

    if (abs(res - s1 / s2) > 1e-5)
    {
        cout << "Ops, jury has better solution: " << res << '\n';
        cout << "            Provided solution: " << s1 / s2 << '\n';
        exit(0);
    }
}

int main()
{
    FOR(i, 1, ntest)
    {
        GenTest();
        system(name".exe <"name".inp> "name".out");
        system(name"_trau.exe <"name".inp> "name".ans");

        GetResult();
        CheckResult();

        cout << "Test " << i << ": Good boy, you have the same answer with jury!\n";
    }

    return 0;
}