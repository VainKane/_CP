#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define all(v) v.begin(), v.end()
#define name "remainder"

int const N = 230;

string a;
long long b;
long long pw[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> a >> b;

    b = abs(b);

    pw[0] = 1;
    FOR(i, 1, a.size()) pw[i] = (unsigned long long) pw[i - 1] * 10 % b;

    bool negative = a[0] == '-';

    reverse(all(a));
    long long r = 0;

    REP(i, a.size()) if (a[i] != '-') 
        r = (r + (unsigned long long)(a[i] - '0') * pw[i]) % b;

    cout << (negative ? (-r + b) % b : r);

    return 0;
}