#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define F first
#define S second
#define name "CHONBI"

int const N = 1e4 + 5;

int n;
int m;
pii a[N];

long long res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> a[i].S >> a[i].F;

    sort(a + 1, a + m + 1, greater<pii> ());
    
    for (int i = 1; i <= m; i++)
    {
        if (n <= 0) break;
        res += 1ll * min(n, a[i].S) * a[i].F;
        n -= a[i].S; 
    }   

    cout << res;

    return 0;
}