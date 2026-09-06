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

int n, m;
vector<int> nodes[N];
int pos[N];

bool Check(int idx)
{
    FOR(i, 0, sz(nodes[idx]) - 2) if (pos[nodes[idx][i]] >= pos[nodes[idx][i + 1]]) return false;
    return true;
}

int Cal()
{
    FOR(i, 1, m) if (!Check(i)) return i - 1;
    return m;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    FOR(i, 1, m)
    {
        int k; cin >> k;
        while (k--)
        {
            int u; cin >> u;
            nodes[i].push_back(u);
        }
    }

    vector<int> id, res;
    int ma = -1;

    FOR(i, 1, n) id.push_back(i);

    do
    {
        REP(i, n) pos[id[i]] = i;
        if (maxi(ma, Cal())) res = id;
    } while (next_permutation(all(id)));

    for (auto &i : res) cout << i << ' ';
    // cout << ma;

    return 0;
}