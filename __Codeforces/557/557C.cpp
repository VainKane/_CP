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

int const N = 1e5 + 5;
int const oo = 1e9;

int n;

pair<int, int> a[N];
int pre[N];

int cnt[209][N];

int GetCost(int need, int &bd)
{
    if (!bd) return 0;
    int res = 0;

    FOR(i, 1, 200)
    {
        int k = min(need, cnt[i][bd - 1]);
        res += k * i;
        need -= k;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i].F;
    FOR(i, 1, n) cin >> a[i].S, cnt[a[i].S][a[i].F]++;

    sort(a + 1, a + n + 1, greater<pair<int, int>> ());
    FOR(i, 1, 200) FOR(j, 1, 1e5) cnt[i][j] += cnt[i][j - 1];
    
    FOR(i, 1, n) pre[i] = pre[i - 1] + a[i].S;
    int res = oo;

    for (int i = 1; i <= n;)
    {
        int j = i;
        for (; a[i].F == a[j].F; j++);

        int l = 0;
        int r = n;
        int req = r;

        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if ((n - mid) / 2 + 1 <= j - i)
            {
                req = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }

        int need = max(req - i + 1, 0);
        mini(res, pre[i - 1] + GetCost(need, a[i].F));

        i = j;
    }

    cout << res;

    return 0;
}