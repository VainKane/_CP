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

int const N = 1e6 + 5;

long long Ceil(long long a, long long b)
{
    if (b < 0) a = -a, b = -b;
    return (a ^ b) < 0 ? a / b : (a + b - 1) / b;
}

struct Segment
{
    long long x, a, b;

    long long Val()
    {
        return a * x + b;
    }
};

struct ConvexHullTrick
{
    vector<Segment> seg;
    int id = 0;

    void Reset()
    {
        seg.clear();
        id = 0;
    }

    void Add(long long a, long long b)
    {
        while (!seg.empty())
        {
            if (seg.back().Val() >= seg.back().x * a + b) seg.pop_back();
            else break;
        }

        if (seg.empty()) seg.push_back({0, a, b});
        else
        {
            if (a == seg.back().a) return;
            seg.push_back({Ceil(b - seg.back().b, seg.back().a - a), a, b});
        }
    }

    long long Get(int x)
    {
        mini(id, sz(seg));
        for (; id < sz(seg) && seg[id].x <= x; id++);
        id--;

        return x * seg[id].a + seg[id].b;
    }
} cht;

int n, k;
long long c;

long long v[N];

namespace Sub1
{
    bool CheckSub()
    {
        return k == 1;
    }

    void Process()
    {
        long long res = 2 * n * c;
        FOR(i, 1, n) res += v[i] * (2 * n - i);
        cout << res;
    }
}

namespace Sub5
{
    bool CheckSub()
    {
        return n <= 1e5;
    }

    int const N = 1e5 + 5;
    int const K = 907;

    long long pre[N], preI[N];
    long long dp[N][K];

    void Process()
    {
        FOR(i, 1, n)
        {
            pre[i] = pre[i - 1] + v[i];
            preI[i] = preI[i - 1] + i * v[i];
        }

        mini(k, 900);
        
        memset(dp, 0x3f, sizeof dp);
        dp[0][0] = 0;

        FOR(j, 1, k)
        {
            cht.Reset();

            FOR(i, 1, n)
            {
                cht.Add(-2 * pre[i - 1], dp[i - 1][j - 1] + preI[i - 1]);
                dp[i][j] = cht.Get(i) + 2 * i * (c + pre[i]) - preI[i];
            }
        }

        cout << *min_element(dp[n] + 1, dp[n] + k + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k >> c;
    FOR(i, 1, n) cin >> v[i];

    if (Sub1::CheckSub()) return Sub1::Process(), 0;
    if (Sub5::CheckSub()) return Sub5::Process(), 0;

    return 0;
}