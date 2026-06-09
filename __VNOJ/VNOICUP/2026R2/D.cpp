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

int const N = 36;

int n;
int a[N];

namespace Sub1
{
    bool CheckSub()
    {
        return n <= 20;
    }

    bool Check(vector<int> &v)
    {
        int pre = -1;
        FOR(i, 1, sz(v) - 1)
        {
            if (v[i] == v[i - 1]) return false;
            bool haha = v[i] > v[i - 1];
            if (haha == pre) return false;
            pre = haha;
        }

        return true;
    }

    void Process()
    {
        REP(mask, MK(n))
        {
            vector<int> v1, v2;
            REP(i, n)
            {
                if (BIT(i, mask)) v1.push_back(a[i + 1]);
                else v2.push_back(a[i + 1]);
            }

            if (Check(v1) && Check(v2))
            {
                cout << "YES\n";
                REP(i, n) cout << BIT(i, mask) + 1 << ' ';
                cout << '\n';
                return;
            }
        }

        cout << "NO\n";
    }
}

namespace Sub2
{
    bool CheckSub()
    {
        return n <= 2000;
    }

    int id[N];
    int cnt[2009];

    void Compress()
    {
        vector<int> vals;

        FOR(i, 1, n) vals.push_back(a[i]);
        sort(all(vals));
        vals.erase(unique(all(vals)), vals.end());

        FOR(i, 1, n) a[i] = lower_bound(all(vals), a[i]) - vals.begin() + 1;
    }

    bool Check()
    {
        memset(cnt, 0, (n + 1) * sizeof(int));
        FOR(i, 1, n) if (++cnt[a[i]] == 3) return false;
        FOR(i, 1, n) FOR(j, i + 1, n) if (a[i] == a[j]) id[j] = 2;
        return true;
    }

    void Process()
    {
        Compress();

        FOR(i, 1, n) id[i] = 1;
        if (Check())
        {
            cout << "YES\n";
            FOR(i, 1, n) cout << id[i] << ' ';
            cout << '\n';
        }
        else cout << "NO\n";
    }
}

void Solve()
{
    // if (Sub1::CheckSub()) return Sub1::Process();
    if (Sub2::CheckSub()) return Sub2::Process();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n;
        FOR(i, 1, n) cin >> a[i];
        Solve();
    }

    return 0;
}