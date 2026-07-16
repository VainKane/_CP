#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "match"

int const N = 15;

int n;
int a[N], b[N];

int minDist = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];

    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);

    FOR(i, 1, n) minDist += abs(a[i] - b[i]);

    int res = 0;

    do
    {
        int sum = 0;
        FOR(i, 1, n) sum += abs(a[i] - b[i]);
        res += sum == minDist;
    } while (next_permutation(a + 1, a + n + 1));

    cout << res;

    return 0;
}