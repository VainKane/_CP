#include <bits/stdc++.h>
using namespace std;

#define TASKNAME "TASKNAME"
#define sp ' '
#define endl '\n'
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)

template <class T> bool mini(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template <class T> bool maxi(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

using ll = long long;
using pii = pair<int, int>;

const int maxn = 1e5 + 5;
int n;
int a[maxn];
vector<int> g[maxn];

void enter() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    for (int i = 1, u, v; i < n; ++i) cin >> u >> v, g[u].push_back(v), g[v].push_back(u);
}

int f[maxn];
int d[maxn];
int sz = 0;

void dfs(int u) {
    bool leaf = 1;
    for (const int &v: g[u]) if (not d[v]) d[v] = d[u] + 1, leaf = 0, dfs(v);
    if (leaf) f[u] = 1, sz++;
}

int need[maxn];
int res;

void dfs2(int u) {
    for (const int &v: g[u]) if (d[u] < d[v]) dfs2(v), f[u] += f[v];
    int take = min(f[u], need[u]);
    f[u] -= take;
    res += take;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    if (fopen(TASKNAME".inp", "r")) {
        freopen(TASKNAME".inp", "r", stdin);
        freopen(TASKNAME".out", "w",  stdout);
    }
    
    enter();

    d[1] = 1;
    dfs(1);

    FOR(i, 1, sz) need[a[i]]++;
    dfs2(1);

    cout << res << endl;

    return 0;
}