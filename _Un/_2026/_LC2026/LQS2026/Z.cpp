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

int const N = 2e5 + 5;
int const M = 1e6 + 5;

int n, m;
int a[N], x[N];

vector<int> divs[M], pos[M];
int res[M];

void Sieve()
{
    FOR(i, 2, 1000) for (int j = i * i; j <= 1e6; j += i)
    {
        divs[j].push_back(i);
        if (i * i != j) divs[j].push_back(j / i);
    }

    FOR(i, 1, 1e6)
    {
        divs[i].push_back(i);
        pos[i].push_back(m + 1);
    }
}

int Get(int val, int i)
{
    int res = m + 1;
    for (auto &x : divs[val]) mini(res, pos[x][lower_bound(all(pos[x]), i) - pos[x].begin()]);
    return res;
}

int Solve(int val)
{
    int idx = 0;
    while (val > 1)
    {
        idx = Get(val, idx + 1);
        if (idx > m) break;
        val /= x[idx];
    }

    return val;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, m) cin >> x[i], pos[x[i]].push_back(i);

    Sieve();

    FOR(i, 1, n)
    {
        if (!res[a[i]]) res[a[i]] = Solve(a[i]);
        cout << res[a[i]] << ' ';
    }

    return 0;
}