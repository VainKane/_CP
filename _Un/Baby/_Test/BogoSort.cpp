#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
int const N = 1e6 + 5;

int n;
int a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    while (!is_sorted(a + 1, a + n + 1)) shuffle(a + 1, a + n + 1, mt19937_64(time(0)));
    FOR(i, 1, n) cout << a[i] << ' ';

    return 0;
}