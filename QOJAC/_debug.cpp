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
#define name "2742"

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

    string haha = "ABXY";
    string moves;

    char ini = haha[Rand(0, 3)];
    for (auto &ch : haha) if (ch != ini) moves.push_back(ch);    

    int n = Rand(1, 1000);
    cout << n << '\n';
    cout << ini;
    FOR(i, 2, n) cout << moves[Rand(0, 2)];
}

int main()
{
    FOR(i, 1, ntest)
    {
        GenTest();
        system(name".exe");
    }

    return 0;
}