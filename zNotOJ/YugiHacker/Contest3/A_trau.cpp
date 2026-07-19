#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
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

    int res = 0;

    FOR(i, 1, 1e3) 
    {
        int tmp = 0;
        FOR(j, 1, n) tmp += (a[j].F <= i && a[j].S >= i);
        res = max(res, tmp);
    } 
    
    cout << res;

    return 0;
}