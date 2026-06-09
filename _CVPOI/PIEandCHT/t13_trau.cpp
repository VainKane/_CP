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

int n, q, a;
int v[N];

namespace Sub3
{
    bool CheckSub()
    {
        return true;
        // return n * q <= 5e6;
    }

    long long pre[N], c[N];

    void Process()
    {
        FOR(i, 1, n) pre[i] = pre[i - 1] + v[i];

        while (q--)
        {
            int r; cin >> r;
            FOR(i, 1, n) c[i] = 1LL * a * v[i] + pre[i - 1] - (r - 1LL) * v[i] + 1LL * (i - 1) * v[i];

            sort(c + 1, c + n + 1);

            long long res = 0;
            FOR(i, 1, r) res += c[i];
            cout << res << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q >> a;
    FOR(i, 1, n) cin >> v[i];

    if (Sub3::CheckSub()) return Sub3::Process(), 0;

    return 0;
}