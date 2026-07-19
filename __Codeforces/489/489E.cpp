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
double const eps = 1e-10;

int n, l;
int x[N], b[N];

double dp[N];
int trace[N];

bool Check(double &r)
{
    if (r == 0) return false;

    FOR(i, 1, n) 
    {
        dp[i] = sqrt(abs(x[i] - l)) - r * b[i];
        FOR(j, 1, i - 1) if (mini(dp[i], dp[j] + sqrt(abs(x[i] - x[j] - l)) - r * b[i])) trace[i] = j;
    }

    return dp[n] <= 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> l;
    FOR(i, 1, n) cin >> x[i] >> b[i];

    double l = 0;
    double r = 1e9;
    double hihi = r;

    while (r - l >= eps)
    {
        double mid = (l + r) / 2;
        if (Check(mid))
        {
            hihi = mid;
            r = mid;
        }
        else l = mid;
    }

    memset(trace, 0, sizeof trace);
    Check(hihi);
    vector<int> res;

    int idx = n;
    while (idx)
    {
        res.push_back(idx);
        idx = trace[idx];
    }

    reverse(all(res));
    for (auto &id : res) cout << id << ' ';

    return 0;
}