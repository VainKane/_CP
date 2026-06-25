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
#define name "hanoihn6"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

mt19937_64 rd(time(0));
ll Rand(ll l, ll r) { return l + rd() * 1LL * rd() % (r - l + 1); }

int const ntest = 1e4;

int n;

void GenTest()
{
    ofstream cout(name".inp");
    int const lim = 8;
    n = Rand(1, lim);
    cout << n;
}

void Judge()
{
    ifstream cin(name".out");
    vector<int> v[4];
    FORD(i, n, 1) v[0].push_back(i);

    int t; cin >> t;
    FOR(haha, 1, t)
    {
        char x, y;
        cin >> x >> y;
        x -= 'A', y -= 'A';

        if (sz(v[y]) && v[y].back() < v[x].back())
        {
            cout << "Move: " << haha << " is illegal!\n";
            exit(0);
        }
        else v[y].push_back(v[x].back()), v[x].pop_back();
    }

    if (sz(v[3]) != n)
    {
        cout << "Not enough: " << sz(v[3]);
        exit(0);
    }

    FOR(i, 1, n - 1) if (v[3][i] != v[3][i - 1] - 1)
    {
        cout << "Not sorted yet, the seq is:\n";
        FORD(j, n - 1, 0) cout << v[3][j] << ' ';
        exit(0); 
    }
}

int main()
{
    FOR(i, 1, ntest)
    {
        GenTest();
        system("./"name" <"name".inp> "name".out");
        Judge();

        cout << "Test: " << i << " CORRECT!\n";
    }

    return 0;
}