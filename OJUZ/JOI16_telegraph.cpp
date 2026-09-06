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

int n;
int a[N], c[N];

bool visited[N];
int id[N];

vector<int> gr[N];
int cc = 0;

int deg[N];

ll d[N];
ll sum[N], mxD[N];
ll mxCD[N];

vector<int> st;

void DFS(int u)
{
    st.push_back(u);
    visited[u] = true;
    if (!visited[a[u]]) DFS(a[u]);
}

void Update(int u)
{
    if (st.empty()) return;
    int v = st.back();
    
    ll dist = max(d[u] + c[v], mxCD[id[u]]);
    id[v] = id[u];
    maxi(mxD[id[u]], d[v] = dist);

    st.pop_back();
    while (!st.empty())
    {
        v = st.back();
        st.pop_back();

        d[v] = dist += c[v];
        id[v] = id[u];

        maxi(mxD[id[u]], d[v]);
    }
}

void ZeroLmao()
{
    int idx = 1;
    REP(haha, n) visited[idx = a[idx]] = 1;
    
    FOR(i, 2, n) if (!visited[i]) return;
    FOR(i, 1, n) if (deg[i] != 1) return;

    cout << 0;
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i] >> c[i], deg[a[i]]++;

    ZeroLmao();
    memset(visited, false, sizeof visited);

    FOR(i, 1, n) if (!visited[i])
    {
        DFS(i);
        int u = a[st.back()];

        if (!id[u])
        {
            cc++;
            for (auto &v : st)
            {
                gr[cc].push_back(v);
                sum[cc] += c[v];
                id[v] = cc;
            }

            vector<int> nodes = {u};
            ll dist = c[u];

            while (st.back() != u)
            {
                int v = st.back();
                st.pop_back();

                nodes.push_back(v);
                dist += c[v];
            }

            st.pop_back();

            for (auto &v : nodes) d[a[v]] = -c[v];
            for (auto &v : nodes) maxi(mxD[cc], d[v] += dist);
            mxCD[cc] = mxD[cc];

            Update(u);
        }
        else
        {
            for (auto &v : st)
            {
                gr[id[u]].push_back(v);
                sum[id[u]] += c[v];
            }

            Update(u);
        }
    }

    ll res = 0;
    FOR(i, 1, cc) res += sum[i] - mxD[i];
    cout << res;

    return 0;
}