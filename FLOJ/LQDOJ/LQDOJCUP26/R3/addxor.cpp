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
#define name "addxor"

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 1e5 + 5;

int n, b, q;
ll a[N];

namespace Sub1
{
    bool CheckSub() { return true; }

    int const M = 1e6 + 5;
    
    bool visited[M];

    void BFS()
    {
        queue<int> q;
        FOR(i, 1, n) q.push(a[i]), visited[a[i]] = true;

        while (!q.empty())
        {
            int u = q.front(); q.pop();

            if (u + b <= 1e6 && !visited[u + b])
            {
                visited[u + b] = true;
                q.push(u + b);
            }

            if ((u ^ b) <= 1e6 && !visited[u ^ b])
            {
                visited[u ^ b] = true;
                q.push(u ^ b);
            }
        }
    }

    void Process()
    {
        BFS();

        vector<int> v = {0};
        FOR(i, 1, 1e6) if (visited[i]) v.push_back(i);
        
        while (q--)
        {
            int k; cin >> k;
            cout << v[k] << ' ';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> b >> q;
    FOR(i, 1, n) cin >> a[i];

    if (Sub1::CheckSub()) return Sub1::Process(), 0;

    return 0;
}