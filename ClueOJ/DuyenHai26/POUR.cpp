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

int n;
vector<long long> s;
set<vector<long long>> visited;
map<vector<long long>, pair<int, int>> trace;

int res = 0;
vector<long long> st;

int Count(vector<long long> &v)
{
    int cnt = 0;
    for (auto &x : v) cnt += x == 0;
    return cnt;
}

void BFS()
{
    queue<vector<long long>> q;
    q.push(s);

    visited.insert(s);
    int cnt = 0;

    while (!q.empty())
    {
        auto v = q.front();
        q.pop();

        if (maxi(res, Count(v))) st = v;
        if (++cnt > 5e4) return;

        REP(i, n) REP(j, n) if (i != j && v[i] >= v[j])
        {
            v[i] -= v[j];
            v[j] <<= 1;

            if (!visited.count(v))
            {
                trace[v] = {i, j};
                visited.insert(v);
                q.push(v);
            }

            v[j] >>= 1;
            v[i] += v[j];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n;

        s.assign(n, 0);
        REP(i, n) cin >> s[i];

        visited.clear();
        trace.clear();
        res = 0;
        st = s;

        BFS();
        vector<pair<int, int>> path;

        while (st != s)
        {
            auto &p = trace[st];
            path.push_back(p);
            st[p.S] >>= 1;
            st[p.F] += st[p.S];
        }

        reverse(all(path));

        cout << sz(path) << '\n';
        for (auto &p : path) cout << p.F + 1 << ' ' << p.S + 1 << '\n';
    }

    return 0;
}