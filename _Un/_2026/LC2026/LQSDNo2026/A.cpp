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

int const N = 109;

int n, m;

int a[N][N];
int cnt[2][2];

ii Find(int p)
{
    FOR(i, 1, m) FOR(j, 1, n)
    {
        if ((i + j) & 1)
        {
            if ((a[i][j] & 1) == p) return {i, j};
        }
        else if ((a[i][j] & 1) != p) return {i, j};
    }

    return {0, 0};
}

void Solve(int p)
{
    FOR(i, 1, m) FOR(j, 1, n)
    {
        if ((i + j) & 1) a[i][j] += (a[i][j] & 1) == p;
        else a[i][j] += (a[i][j] & 1) != p;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n)
    {
        cin >> a[i][j];
        cnt[(i + j) & 1][a[i][j] & 1]++;
    }

    if (cnt[0][0] + cnt[1][1] < cnt[0][1] + cnt[1][0]) Solve(1);
    else if (cnt[0][0] + cnt[1][1] > cnt[0][1] + cnt[1][0]) Solve(0);
    else if (Find(0) > Find(1)) Solve(0);
    else Solve(1);

    FOR(i, 1, m) FOR(j, 1, n) cout << a[i][j] << " \n"[j == n];

    return 0;
}