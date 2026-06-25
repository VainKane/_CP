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
#define name "d5tabn3"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

mt19937_64 rd(time(0));
ll Rand(ll l, ll r) { return l + rd() * 1LL * rd() % (r - l + 1); }

int const ntest = 1e4;

int n;
vector<vector<int>> v;

void GetNew(int mi1, int mi2, int ma, int x, int &nmi1, int &nmi2, int &nma)
{
    nmi1 = min(x, mi1);
    nmi2 = x <= mi1 ? mi1 : min(x, mi2);
    nma = max(x, ma);
}

void Try(int pos, int mi1, int mi2, int ma, vector<int> seq)
{
    if (pos > n)
    {
        v.push_back(seq);
        return;
    }

    FOR(i, 1, n)
    {
        int nmi1, nmi2, nma;
        GetNew(mi1, mi2, ma, i, nmi1, nmi2, nma);

        if (nmi1 + nmi2 > nma)
        {
            seq.push_back(i);
            Try(pos + 1, nmi1, nmi2, nma, seq);
            seq.pop_back();
        }
    }
}


void GenTest()
{
    ofstream cout(name".inp");

    int const lim = 500;
    int const oo = 1e9;

    n = Rand(1, lim);
    int x = Rand(0, n);
    int y = Rand(0, n - x);
    int z = Rand(0, n - x - y);

    cout << n << ' ' << x << ' ' << y << ' ' << z << '\n';
    FOR(i, 1, n) REP(i, 3) cout << Rand(1, oo) << ' ';
}

int main()
{
    FOR(i, 1, ntest)
    {
        GenTest();
        system("./"name" <"name".inp> "name".out");
        system("./"name"_brute <"name".inp> "name".ans");

        if (system("diff "name".out "name".ans") != 0)
        {
            cout << "Test: " << i << " WRONG!\n";
            return 0;
        }

        cout << "Test: " << i << " CORRECT!\n";
    }

    return 0;
}