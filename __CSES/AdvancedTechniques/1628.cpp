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

int n, x;
int a[N];

vector<long long> vals1, vals2;

void Build(int idx, int n, vector<long long> &vals)
{
    REP(mask, MK(n))
    {
        long long s = 0;
        for (int tmp = mask; tmp; tmp ^= tmp & -tmp)
        {
            int i = __builtin_ctz(tmp);
            s += a[idx + i];
        }

        vals.push_back(s);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> x;
    REP(i, n) cin >> a[i];

    int n1 = n / 2, n2 = n - n1;
    Build(0, n1, vals1);
    Build(n1, n2, vals2);

    sort(all(vals1));

    long long res = 0;
    for (auto &val : vals2) res += upper_bound(all(vals1), x - val) - lower_bound(all(vals1), x - val);
    cout << res;

    return 0;
}