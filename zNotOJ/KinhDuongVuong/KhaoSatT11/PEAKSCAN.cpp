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
#define name "PEAKSCAN"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 5e5 + 5;

int n, q;

int a[N];
pair<int, int> qr[N];

namespace Sub1
{
    bool CheckSub()
    {
        return n <= 7000 && q <= 7000;
    }

    void Solve()
    {
        FOR(i, 1, q)
        {
            if (qr[i].F == 1)
            {
                long long res = 0;
                deque<int> dq;

                int k = qr[i].S;
                int j = 1;
                FOR(i, 1, n)
                {
                    while (!dq.empty() && i - dq.front() >= k) dq.pop_front();
                    while (!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();
                    dq.push_back(i);

                    if (i >= k) res += a[dq.front()];
                }

                cout << res << '\n';
            }
            else a[qr[i].S]++;
        }
    }
}

namespace Sub2
{
    int const LOG = 20;

    long long res[N];
    int up[N][22];
    int lg[N];

    bool CheckSub()
    {
        FOR(i, 1, q) if (qr[i].F == 2) return false;
        return true;
    }

    void Build()
    {
        FOR(i, 1, n) up[i][0] = a[i];
        FOR(j, 1, LOG) FOR(i, 1, n - MK(j) + 1)
            up[i][j] = max(up[i][j - 1], up[i + MK(j - 1)][j - 1]);

        FOR(i, 2, n) lg[i] = lg[i / 2] + 1;
    }

    int GetMax(int l, int r)
    {
        int k = lg[r - l + 1];
        return max(up[l][k], up[r - MK(k) + 1][k]);
    }

    void Solve()
    {
        Build();
        FOR(k, 1, n) FOR(i, 1, n - k + 1) res[k] += GetMax(i, i + k - 1);

        FOR(i, 1, q) cout << res[qr[i].S] << '\n';
    }
}

int main()
{
    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, q) cin >> qr[i].F >> qr[i].S;

    if (Sub1::CheckSub()) return Sub1::Solve(), 0;
    if (Sub2::CheckSub()) return Sub2::Solve(), 0;

    return 0;
}
