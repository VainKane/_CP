#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()
#define F first
#define S second

int const N = 2e5 + 5;

int n;
pair<int, int> a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i].F >> a[i].S;

    FOR(i, 1, n) 
    {
        int res = 0;
        FOR(j, 1, n) if (i != j) res += (a[j].F <= a[i].F && a[j].S >= a[i].S);
        cout << res << ' ';
    }

    return 0;
}