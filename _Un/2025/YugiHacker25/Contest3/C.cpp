#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define F first
#define S second
#define name "match"

int const N = 1e5 + 5;
int const MOD = 1e9 + 7;

int n;
pair<int, int> events[2 * N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);
 
    cin >> n;
    FOR(i, 1, n)
    {
        int x; cin >> x;
        events[i] = {x, 1};
    }
    FOR(i, 1, n)
    {
        int x; cin >> x;
        events[n + i] = {x, -1};
    }

    sort(events + 1, events + 2 * n + 1);

    int sum = 0;
    int res = 1;

    FOR(i, 1, 2 * n)
    {
        int x = events[i].S;
        if (x == 1 && sum < 0) res = 1ll * res * -sum % MOD;
        else if (x == -1 && sum > 0) res = 1ll * res * sum % MOD;
        sum += x;
    }

    cout << res;

    return 0;
}