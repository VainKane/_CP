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
#define name "build-bbs"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 22;
int const M = MK(20) + 5;

int n;

int a[N];
int sum[M];

bool dp[N][M];
int trace[N][M];
int par[N];

char res[2 * N];
int pos[N];

vector<int> adj[N];

void PrintNo()
{
    cout << "No";
    exit(0);
}

void BFS()
{
    queue<int> q;
    int j = 1;
    
    FORD(i, n, 1) if (!par[i]) q.push(i);

    while (!q.empty())
    {
        int i = q.front(); q.pop();

        pos[i] = par[i] ? pos[par[i]] : j;
        int k = pos[i] + 2 * (a[i] - 1) + 1;

        res[pos[i]] = '(', res[k] = ')';

        if (!par[i]) j = k + 1;
        else pos[par[i]] = k + 1;
        pos[i]++;

        for (auto &v : adj[i]) q.push(v);
    }
}

void Solve()
{
    REP(mask, MK(n)) if (dp[n][mask])
    {
        cout << "Yes\n";
        FORD(i, n, 2)
        {
            for (int tmp = trace[i][mask]; tmp; tmp ^= tmp & -tmp)
            {
                int j = __builtin_ctz(tmp);
                par[j + 1] = i;
            }

            mask ^= trace[i][mask];
        }

        FOR(i, 1, n) adj[par[i]].push_back(i);
        BFS();

        FOR(i, 1, 2 * n) cout << res[i];
        return;
    }

    PrintNo();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    FOR(i, 1, n)
    {
        cin >> a[i];
        if (a[i] & 1) PrintNo();
        a[i] = a[i] / 2 + 1;
    }

    sort(a + 1, a + n + 1);
    FOR(mask, 1, MK(n) - 1)
    {
        int i = __builtin_ctz(mask);
        sum[mask] = sum[mask ^ MK(i)] + a[i + 1];
    }

    dp[1][0] = a[1] == 1;
    FOR(i, 1, n - 1) REP(mask, MK(i)) if (dp[i][mask])
    {
        dp[i + 1][mask] |= (a[i + 1] == 1);
        int inv = (MK(i) - 1) ^ mask;

        for (int s = inv; s; s = (s - 1) & inv) if (sum[s] == a[i + 1] - 1)
        {
            trace[i + 1][mask ^ s] = s;
            dp[i + 1][mask ^ s] = true;
        }
    }

    Solve();

    return 0;
}