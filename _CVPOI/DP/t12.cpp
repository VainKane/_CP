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

int const N = 1009;

int n, k;
int s[N], t[N], c[N];
vector<int> vals;

void Compress()
{
    FOR(i, 1, n)
    {
        vals.push_back(s[i]);
        vals.push_back(t[i]);
    }

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n)
    {
        s[i] = lower_bound(all(vals), s[i]) - vals.begin() + 1;
        t[i] = lower_bound(all(vals), t[i]) - vals.begin() + 1;
    }
}

namespace Sub1
{
    bool CheckSub()
    {
        return n <= 20;
    }

    int d[67];

    int Cal(int mask)
    {
        int res = 0, ma = 0;

        for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
        {
            int i = __builtin_ctz(tmp);
            d[s[i + 1]]++, d[t[i + 1] + 1]--;
            res += c[i + 1];
        }

        int pre = 0;
        FOR(i, 1, sz(vals)) maxi(ma, pre += d[i]);

        for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
        {
            int i = __builtin_ctz(tmp);
            d[s[i + 1]] = d[t[i + 1] + 1] = 0;
        }

        return ma <= k ? res : 0;
    }

    void Process()
    {
        int res = 0;
        REP(mask, MK(n)) maxi(res, Cal(mask));
        cout << res;
    }
}

namespace Sub2
{
    bool CheckSub()
    {
        return k == 1;
    }

    vector<int> id[2 * N];
    int dp[2 * N];

    void Process()
    {
        FOR(i, 1, n) id[t[i]].push_back(i);
        FOR(r, 1, sz(vals)) 
        {
            dp[r] = dp[r - 1];
            for (auto &i : id[r]) maxi(dp[r], dp[s[i] - 1] + c[i]);
        }

        cout << dp[sz(vals)];
    }
}

namespace Sub3
{
    bool CheckSub()
    {
        return k == 2;
    }

    int dp[N][N];

    void Process()
    {
        FOR(i, 1, sz(vals)) FOR(j, 1, sz(vals)) FOR(id, 1, n)
        {
            if (t[id] <= i) maxi(dp[i][j], dp[s[id] - 1][j] + c[id]);
            if (t[id] <= j) maxi(dp[i][j], dp[i][s[id] - 1] + c[id]);
        }

        cout << dp[sz(vals)][sz(vals)];
    }
}

namespace Sub4
{
    bool CheckSub()
    {
        return true;
    }

    vector<int> id[2 * N];
    int ed[67];

    bool cmp(int i, int j)
    {
        return c[i] > c[j];
    }

    void Process()
    {
        int res = 0;

        FOR(i, 1, n) id[t[i]].push_back(i);
        FOR(r, 1, sz(vals)) sort(all(id[r]), cmp);

        ed[0] = -1;

        FOR(r, 1, sz(vals)) for (auto &i : id[r])
        {
            int idx = 0;
            FOR(j, 1, k) if (ed[j] < s[i] && ed[j] > ed[idx]) idx = j;
            if (idx == 0) break;

            ed[idx] = r;
            res += c[i];
        }

        cout << res;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n) 
    {
        cin >> s[i] >> t[i] >> c[i];
        t[i] += s[i] - 1;
    }

    Compress();

    if (Sub1::CheckSub()) return Sub1::Process(), 0;
    if (Sub2::CheckSub()) return Sub2::Process(), 0;
    if (Sub3::CheckSub()) return Sub3::Process(), 0;
    if (Sub4::CheckSub()) return Sub4::Process(), 0;

    return 0;
}