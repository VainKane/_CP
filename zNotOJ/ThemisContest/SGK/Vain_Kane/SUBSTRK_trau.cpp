#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "SUBSTRK"

int const N = 1e6 + 5;

int n, k;
string s;

int cnt[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> k >> s;
    n = s.size();
    s = " " + s;

    FOR(i, 1, n) cnt[i] = cnt[i - 1] + (s[i] == '1');

    long long res = 0;
    FOR(i, 1, n) FOR(j, 1, i - 1) res += cnt[i] - cnt[j - 1] == k;
    cout << res;

    return 0;
}