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

int const N = 509;

int n;
bitset<N> go[N];

bool used[N];
int cnt[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n;
        FOR(i, 1, n) FOR(j, 1, n) go[i][j] = false;
        FOR(i, 1, n) FOR(j, 1, n) 
        {
            char ch; cin >> ch;
            go[i][j] = ch - '0';
        }

        FOR(u, 1, n) cnt[u] = go[u].count();

        FOR(u, 1, n)
        {
            memset(used, false, sizeof used);

            int node = 0;
            FOR(v, 1, n) if (go[u][v] && cnt[v] > cnt[node]) node = v;
            
        }

        vector<pair<int, int>> edges;
    }

    return 0;
}