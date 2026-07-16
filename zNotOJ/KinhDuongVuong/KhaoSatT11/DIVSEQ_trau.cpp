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
#define name "DIVSEQ"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 1e6 + 5;

int n, q;
int a[N];

namespace Sub1
{
    bool CheckSub()
    {
        return n <= 1000;
//        return true;
    }

    bool Check(int l, int r)
    {
        vector<int> tmp;
        FOR(i, l, r) tmp.push_back(a[i]);
        sort(all(tmp));

        FOR(i, 1, sz(tmp) - 1) if (tmp[i] % tmp[i - 1]) return false;
        return true;
    }

    void Solve()
    {
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            cout << (Check(l, r) ? "YES\n" : "NO\n");
        }
    }
}

namespace Sub3
{
    int cntDiv[N][2];

    int fi = 0, se = 0;
    bool CheckSub()
    {
        FOR(i, 1, n)
        {
            if (!fi) fi = a[i];
            else if (a[i] != fi)
            {
                if (se && a[i] != se) return false;
                se = a[i];
            }
        }
        return true;
    }

    bool Check(int l, int r)
    {
        int cnt[] = {0, 0};
        REP(i, 2) cnt[i] = cntDiv[r][i] - cntDiv[l - 1][i];

        if (!cnt[0] || !cnt[1]) return true;
        if (fi % se == 0) return true;
        if (se % fi == 0) return true;

        return false;
    }

    void Solve()
    {
        FOR(i, 1, n)
        {
            cntDiv[i][0] = cntDiv[i - 1][0] + (a[i] == fi);
            cntDiv[i][1] = cntDiv[i - 1][1] + (a[i] == se);
        }


        while (q--)
        {
            int l, r;
            cin >> l >> r;
            cout << (Check(l, r) ? "YES\n" : "NO\n");
        }
    }
}

int main()
{
    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];

    if (Sub1::CheckSub()) return Sub1::Solve(), 0;
    // if (Sub3::CheckSub()) return Sub3::Solve(), 0;

    return 0;
}
