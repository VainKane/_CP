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

struct FenwickTree
{
    vector<long long> bit;
    int n;

    FenwickTree(int _n = 0)
    {
        n = _n;
        bit.assign(n + 5, 0);
    }

    void Update(int idx, int val)
    {
        while (idx <= n)
        {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int Search(int val)
    {
        int pos = 0;
        long long s = 0;

        FORD(i, 31 - __builtin_clz(n), 0) if ((pos | MK(i)) <= n && s + bit[pos | MK(i)] <= val)
            s += bit[pos |= MK(i)];

        return pos + 1;
    }
};

int const N = 1e5 + 5;

int n, q;
pair<int, int> s[N];

bool mark[N];

int res[N];
FenwickTree bit;
int id[N];

void SolveTrace()
{
    int a, b, k;
    cin >> a >> b >> k;

    while (k--)
    {
        int i; cin >> i;
        mark[i] = true;
    }

    vector<int> v;
    FOR(i, 1, n) if (!mark[i]) v.push_back(id[i]);
    sort(all(v));

    int cnt = 0;
    for (auto &i : v)
    {
        if (a >= s[i].F) res[s[i].S] = 1, a -= s[i].F;
        else if (b >= s[i].F) res[s[i].S] = 2, b -= s[i].F;
        cnt += res[s[i].S] != 0;
    }

    cout << cnt << '\n';
    FOR(i, 1, n) cout << res[i];
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> s[i].F, s[i].S = i;

    sort(s + 1, s + n + 1);
    FOR(i, 1, n) id[s[i].S] = i;

    bit = FenwickTree(n);
    FOR(i, 1, n) bit.Update(i, s[i].F);

    SolveTrace();
    q--;

    while (q--)
    {
        int a, b, k;
        cin >> a >> b >> k;
    
        vector<int> v;
        while (k--)
        {
            int i; cin >> i;
            v.push_back(id[i]);
        }

        sort(all(v));
        for (auto &i : v) bit.Update(i, -s[i].F);

        int pos = bit.Search(a + b) - 1;
        pos -= upper_bound(all(v), pos) - v.begin();
        cout << max(0, pos - 1) << ' ';

        for (auto &i : v) bit.Update(i, s[i].F);
    }

    return 0;
}