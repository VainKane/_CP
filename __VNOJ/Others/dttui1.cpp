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

int const N = 67;

int n, m;
int w[N], v[N];

vector<pair<int, int>> st1, st2;
vector<int> vals;

int maxVal[MK(20) + 5];

void Build(int idx, int n, vector<pair<int, int>> &st)
{
    REP(mask, MK(n))
    {
        int s = 0, val = 0;

        for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
        {
            int i = __builtin_ctz(tmp);
            s += w[idx + i], val += v[idx + i];
        }

        if (s <= m) st.push_back({s, val});
    }
}

void Compress()
{
    for (auto &p : st1) vals.push_back(p.F);
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    for (auto &p : st1) maxi(maxVal[lower_bound(all(vals), p.F) - vals.begin() + 1], p.S);
    FOR(i, 1, sz(vals)) maxi(maxVal[i], maxVal[i - 1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    REP(i, n) cin >> w[i] >> v[i];

    int n1 = n / 2, n2 = n - n1;

    Build(0, n1, st1);
    Build(n1, n2, st2);

    Compress();

    unsigned int res = 0;
    for (auto &p : st2) maxi(res, (unsigned int)maxVal[upper_bound(all(vals), m - p.F) - vals.begin()] + p.S);
    cout << res;

    return 0;
}