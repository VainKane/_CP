#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "CAMDIEN"

int const N = 1e5 + 5;

int n, m;
int a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];

    sort(a + 1, a + n + 1, greater<int> ());

    int res = 0;
    FOR(i, 1, n)
    {
        res++;
        if (a[i] >= m) 
        {
            cout << res;
            return 0;
        }
        
        m -= a[i] - 1;
    }

    cout << -1;

    return 0;
}