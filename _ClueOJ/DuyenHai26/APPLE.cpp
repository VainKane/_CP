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

using ll = long long;
using ii = pair<int, int>;

template <class t> bool maxi(t &x, t const &y) { return x < y ? x = y, 1 : 0; }
template <class t> bool mini(t &x, t const &y) { return x > y ? x = y, 1 : 0; }

int const N = 1009;
int const lim = 936;

int n, s;

int w[N];
vector<int> adj[N];

int id[N];
bool mark[N];
bool used[N];

vector<int> ids;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> s;
    FOR(i, 1, n) cin >> w[i];
    FOR(i, 2, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    FOR(i, 1, n) id[i] = i;

    int res = 0;

    auto startTime = chrono::high_resolution_clock::now();
    while (chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count() <= lim)
    {
        int sum = 0;
        FOR(i, 1, n)
        {
            int u = id[i];
            if (mark[u] || sum + w[u] > s) continue;

            sum += w[u];
            used[u] = true;
            for (auto &v : adj[u]) mark[v] = true;
        }

        if (maxi(res, sum))
        {
            ids.clear();
            FOR(u, 1, n) if (used[u]) ids.push_back(u);
        }

        memset(mark, false, sizeof mark);
        memset(used, false, sizeof mark);
        shuffle(id + 1, id + n + 1, mt19937_64(time(0)));
    }

    cout << sz(ids) << '\n';
    for (auto &id : ids) cout << id << ' ';

    return 0;
}