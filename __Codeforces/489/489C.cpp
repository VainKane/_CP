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

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 109;

int n, s;
int res[N];

void PrintNoSolution()
{
    cout << "-1 -1";
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> s;

    if (s == 0 && n > 1) PrintNoSolution();
    if (n * 9 < s) PrintNoSolution();

    int sum = s;

    FOR(i, 1, n)
    {
        int d = max((i == 1 && n > 1) ? 1 : 0, sum - min(sum, 9 * (n - i)));
        sum -= d;

        cout << d;
    }

    sum = 0;
    FOR(i, 1, n) if (sum < s)
    {
        res[i] = min(9, s - sum);
        sum += res[i];
    }

    cout << ' ';
    FOR(i, 1, n) cout << res[i];

    return 0;
}