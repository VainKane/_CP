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
ll const oo = 1e18 + 9;

int n;

int dist[N], cnt[N];
ll d[N];

void BFS(int s)
{
    queue<int> q;
    q.push(s);

    vector<int> v;
    dist[s] = 0;

    while (!q.empty())
    {
        int u = q.front(); q.pop();
        v.push_back(u);

        if (2 * u + 1 <= 2e5 && dist[2 * u + 1] == -1)
        {
            dist[2 * u + 1] = dist[u] + 1;
            q.push(2 * u + 1);
        }
        if (dist[u / 2] == -1)
        {
            dist[u / 2] = dist[u] + 1;
            q.push(u / 2);
        }
    }

    for (auto &x : v)
    {
        cnt[x]++, d[x] += dist[x];
        dist[x] = -1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    memset(dist, -1, sizeof dist);

    cin >> n;
    FOR(i, 1, n)
    {
        int x; cin >> x;
        BFS(x);
    }

    ll res = oo;
    FOR(i, 0, 2e5) if (cnt[i] == n) mini(res, d[i]);
    cout << res;

    return 0;
}