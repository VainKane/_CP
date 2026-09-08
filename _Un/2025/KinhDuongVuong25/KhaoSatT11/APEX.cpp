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
#define name "APEX"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 5009;
int const MOD = 1e9 + 7;

void Add(int &x, int const &y)
{
    x += y;
    if (x >= MOD) x -= MOD;
}

int n;
int a[N];

namespace Sub1
{
    bool mark[20];
    int res = 0;

    bool CheckSub()
    {
        return n <= 10;
    }

    void Try(vector<int> b, int pos)
    {
        if (pos > n)
        {
            int sum = 0;
            FOR(i, 1, n)
            {
                Add(sum, b[i]);
                Add(res, sum);
            }

            return;
        }

        if (!mark[pos]) Try(b, pos + 1);
        else
        {
            FORD(i, pos, 1)
            {
                if (i < pos) swap(b[i], b[i + 1]);
                Try(b, pos + 1);
            }
        }
    }

    void Solve()
    {
        int ma = a[1];
        FOR(i, 2, n)
        {
            if (a[i] > ma) mark[i] = true;
            maxi(ma, a[i]);
        }

        vector<int> b;
        b.assign(n + 1, 0);
        FOR(i, 1, n) b[i] = a[i];

        Try(b, 1);
        cout << res;
    }
}

namespace Sub3
{
    int pos1 = 0, pos2 = 0;
    int sum = 0;
    int pre1[N], pre2[N];

    bool CheckSub()
    {
        int ma = a[1];
        FOR(i, 2, n)
        {
            if (maxi(ma, a[i]))
            {
                if (!pos1) pos1 = i;
                else if (!pos2) pos2 = i;
                else return false;
            }
        }

        return true;
    }

    int GetDelta(int val, int i, int j, int pre[])
    {
        int res = (1LL * val * (i - j) - (pre[i - 1] - pre[j - 1])) % MOD;
        if (res < 0) res += MOD;
        return res;
    }

    void Solve()
    {
        FOR(i, 1, n)
        {
            pre1[i] = (pre1[i - 1] + a[i]) % MOD;
            Add(sum, pre1[i]);
        }

        int val1 = a[pos1];
        int val2 = a[pos2];

        int res = 0;
        FORD(i, pos1, 1)
        {
            int k = GetDelta(val1, pos1, i, pre1);
            Add(res, (sum + k) % MOD);

            if (i < pos1) swap(a[i], a[i + 1]);
            FOR(i, 1, n) pre2[i] = (pre2[i - 1] + a[i]) % MOD;

            FORD(j, pos2, 1) Add(res, (1LL * sum + k + GetDelta(val2, pos2, j, pre2)) % MOD);
        }

        if (pos1 == 0 && pos2 == 0) res = sum;
//        cout << pos1 << ' ' << pos2 << '\n';
        cout << res;
    }
}

int main()
{
    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    if (Sub1::CheckSub()) return Sub1::Solve(), 0;
    if (Sub3::CheckSub()) return Sub3::Solve(), 0;

    return 0;
}
