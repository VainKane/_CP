#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define F first
#define S second

int const N = 1009;

int n, x;
pair<int, int> a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> x;
    FOR(i, 1, n) 
    {
        int val; cin >> val;
        a[i] = {val, i};
    }

    sort(a + 1, a + n + 1);

    FOR(l, 1, n) FOR(r, l + 1, n) FOR(i, r + 1, n) FOR(j, i + 1, n)
    {
        if (1ll * a[l].F + a[r].F + a[i].F + a[j].F == x)
        {   
            cout << a[l].S << ' ' << a[r].S << ' ' << a[i].S << ' ' << a[j].S;
            return 0;
        }
    }

    cout << "IMPOSSIBLE";
    cerr << "IMPOSSIBLE\n";

    return 0;
}