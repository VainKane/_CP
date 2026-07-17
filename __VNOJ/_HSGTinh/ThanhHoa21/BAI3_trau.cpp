#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define name "BAI3"

int const N = 1e5 + 5;

int n, k;
int a[N];

bool used[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];

    sort(a + 1, a + n + 1);

    long long res = 0;

    FORD(i, n, 1) if (!used[i])
    {
        used[i] = true;
        int last = a[i];
        
        FORD(j, i - 1, 1) if (!used[j] && last - a[j] >= k) 
        {
            used[j] = true;
            last = a[j];
        }
        
        res += a[i];
    }

    cout << res;

    return 0;
}
