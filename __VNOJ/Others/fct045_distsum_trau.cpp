#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 1e5 + 5;

int n;
int a[N], b[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i] >> b[i];

    long long res = 0;
    FOR(i, 1, n) FOR(j, i + 1, n) res += abs(a[i] - a[j]) + abs(b[i] - b[j]);
    cout << res;

    return 0;
}