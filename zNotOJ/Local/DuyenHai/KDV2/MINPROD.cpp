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

int const N = 2e5 + 5;
int const M = 36;

int n;
long long x;
long long a[N];

vector<pair<long long, int>> divs;
long long cnt[M][N];

void Factor(long long x)
{
    FOR(i, 2, sqrt(x))
    {
        int cnt = 0;
        while (x % i == 0) 
        {
            cnt++;
            x /= i;
        }
    
        if (cnt) divs.push_back({i, cnt});
    }

    if (x > 1) divs.push_back({x, 1});
}

int Count(long long x, int d)
{
    int res = 0;
    while (x % d == 0)
    {
        res++;
        x /= d;
    }
    return res;
}

bool Check(int l, int r)
{
    REP(idx, sz(divs)) if (cnt[idx][r] - cnt[idx][l - 1] < divs[idx].S) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> x;
    FOR(i, 1, n) cin >> a[i];

    Factor(x);

    REP(idx, sz(divs)) FOR(i, 1, n)
        cnt[idx][i] = cnt[idx][i - 1] + Count(a[i], divs[idx].F);

    int res = n + 1;
    
    int l = 1;
    FOR(r, 1, n) while (l <= r && Check(l, r))
    {
        mini(res, r - l + 1);
        l++;
    }

    if (res == n + 1) res = -1;
    cout << res;

    return 0;
}