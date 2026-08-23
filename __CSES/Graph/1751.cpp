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

int n;
int t[N];

bool visited[N];
int res[N];

vector<int> st;
int len[N];

void DFS(int u)
{
    st.push_back(u);
    visited[u] = true;
    if (!visited[t[u]]) DFS(t[u]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> t[i];

    FOR(i, 1, n) if (!visited[i])
    {
        DFS(i);
        int u = t[st.back()];
        
        if (res[u])
        {
            int cnt = 0;
            while (!st.empty())
            {
                res[st.back()] = ++cnt + res[u];
                st.pop_back();
            }
        }
        else
        {
            int cnt = 1;
            vector<int> nodes = {u};

            while (st.back() != u)
            {
                nodes.push_back(st.back());
                cnt++;
                st.pop_back();
            }

            st.pop_back();

            for (auto &v : nodes) res[v] = cnt;
            while (!st.empty())
            {
                res[st.back()] = ++cnt;
                st.pop_back();
            }
        }
    }

    FOR(u, 1, n) cout << res[u] << ' ';

    return 0;
}