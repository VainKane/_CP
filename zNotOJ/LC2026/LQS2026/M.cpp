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

int const N = 1e5 + 5;

int n, k;
int a[N], p[N];

bool visited[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> p[i];

    ll res = 0;
    FOR(i, 1, n) if (!visited[i])
    {
        visited[i] = true;
        vector<int> v = {i};

        while (!visited[p[v.back()]])
        {
            visited[p[v.back()]] = true;
            v.push_back(p[v.back()]);
        }

        ll sum = 0;
        if (sz(v) <= k + 1)
        {
            for (auto &i : v) sum += a[i];
            maxi(res, sum);
        }
        else
        {
            REP(i, k + 1) sum += a[v[i]];
            REP(i, sz(v))
            {
                maxi(res, sum);
                sum -= a[v[i]], sum += a[v[(i + k + 1) % sz(v)]];
            }
        }
    }

    cout << res;

    return 0;
}