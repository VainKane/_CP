#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "ASUM"

int const N = 1e5 + 5;

int n;
long long s, res = 0;

int a[N];
long long pre[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n >> s;
    FOR(i, 1, n) cin >> a[i];           

    FOR(i, 1, n) pre[i] = pre[i - 1] + a[i];
    FOR(i, 1, n) FOR(j, i, n) res += (abs(pre[j] - pre[i - 1]) > s); 

    cout << res;

    return 0;
}