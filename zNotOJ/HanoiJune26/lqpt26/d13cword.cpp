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

int const N = 36;

int n;
string s[N];

vector<int> adj[N];
int res = N;

bitset<36> col[N];
int c[N];

bool Check(string a, string b)
{
    if (sz(a) != sz(b)) return true;
    REP(i, sz(a)) if (a[i] != b[i] && a[i] != '*' && b[i] != '*') return true;
    return false;
}

void Solve()
{
    memset(c, 0, sizeof c);
    FOR(i, 1, n) FOR(j, 1, n) col[i][j] = 1;

    while (true)
    {
        vector<int> v;
        int mi = n;

        FOR(i, 1, n) if (!c[i])
        {
            if (mini(mi, (int)col[i].count())) v = {i};
            else if (mi == (int)col[i].count()) v.push_back(i);
        }

        if (v.empty()) break;

        shuffle(all(v), mt19937_64(time(0)));
        FOR(i, 1, n) if (col[v.back()][i])
        {
            col[v.back()][i] = 0;
            c[v.back()] = i;
            for (auto &u : adj[v.back()]) col[u][i] = 0;
            break;
        }

        v.pop_back();
    }

    mini(res, *max_element(c + 1, c + n + 1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> s[i];

    FOR(i, 1, n) FOR(j, 1, n) if (Check(s[i], s[j]))
    {
        adj[i].push_back(j);
        adj[j].push_back(i);
    }

    REP(haha, 67) Solve();
    cout << res;

    return 0;
}