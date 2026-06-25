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
#define name ""

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int n;
vector<pair<char, char>> res;

void Solve(int n, char a, char b, char c)
{
    if (n == 1)
    {
        res.push_back({a, c});
        return;
    }

    Solve(n - 1, a, c, b);
    res.push_back({a, c});
    Solve(n - 1, b, a, c);
}

void Solve(int n, char a, char b, char c, char d)
{
    if (n <= 2) return Solve(n, a, b, d);
    int k = n - sqrt(2 * n + 1) + 1;

    Solve(k, a, d, c, b);
    Solve(n - k, a, c, d);
    Solve(k, b, a, c, d);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    Solve(n, 'A', 'B', 'C', 'D');

    cout << sz(res) << '\n';
    for (auto &p : res) cout << p.F << p.S << '\n';

    return 0;
}