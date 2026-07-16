#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 2e4 + 5;

int n, m;
int a[N], b[N];

int s[N * N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, m) cin >> b[i];

    int cnt = 0;
    FOR(i, 1, n) FOR(j, 1, m)
        s[++cnt] = a[i] + b[j];

    sort(s + 1, s + cnt + 1);

    cout << s[(cnt + 1) / 2];

    return 0;
}