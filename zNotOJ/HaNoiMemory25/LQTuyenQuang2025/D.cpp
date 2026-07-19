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

int const N = 1e5 + 5;
int const BK = 314;
int const GR = N / BK + 5;

int n, m;
vector<int> adj[N];
vector<int> v[N];

int cnt[N];
long long sum[GR][N];

int hvId[N];
int hv = 0;

bool mark[N];

void Init()
{
    FOR(i, 1, n) if (cnt[i] > BK) hvId[i] = ++hv;
    FOR(x, 1, n) if (hvId[x]) for (auto &i : v[x]) for (auto &y : adj[i]) sum[hvId[x]][y] += i;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, m)
    {
        int s; cin >> s;
        while (s--)
        {
            int x; cin >> x;
            adj[i].push_back(x);
            v[x].push_back(i);
            cnt[x]++;
        }

        sort(all(adj[i]));
        adj[i].erase(unique(all(adj[i])), adj[i].end());
    }

    Init();

    int q; cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;

        if (cnt[x] < cnt[y]) swap(x, y);
        if (hvId[x]) cout << sum[hvId[x]][y] << '\n';
        else
        {
            long long res = 0;

            for (auto &i : v[x]) mark[i] = true;
            for (auto &i : v[y]) res += i * mark[i];
            for (auto &i : v[x]) mark[i] = false;
            
            cout << res << '\n';
        }
    }

    return 0;
}