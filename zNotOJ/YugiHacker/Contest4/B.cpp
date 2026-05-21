#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define F first
#define S second
#define name "minprod"

int const N = 1e5 + 5;
int const oo = 1e9;

int n;
pair<int, int> a[N];
int sufMax[N];

bool Check(long long x)
{
    FOR(i, 1, n)
    {
        if (1ll * (x + a[i].F - 1) / a[i].F > oo) continue;
        
        int y = (x + a[i].F - 1) / a[i].F;
        int idx = lower_bound(a + i + 1, a + n + 1, make_pair(y, 0)) - a;
        if (1ll * sufMax[idx] * a[i].S >= x) return true;
    }
   
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    FOR(i, 1, n) cin >> a[i].F;
    FOR(i, 1, n) cin >> a[i].S;

    sort(a + 1, a + n + 1);
    FORD(i, n, 1) sufMax[i] = max(sufMax[i + 1], a[i].S);

    long long l = 1;
    long long r = 1e18;
    long long res = l;

    while (l <= r)
    {
        long long mid = (l + r) >> 1;
        if (Check(mid))
        {
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    
    cout << res;

    return 0;
}