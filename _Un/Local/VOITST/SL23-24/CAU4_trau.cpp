#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()
#define name "CAU4"

int n, m;
long long k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n >> m >> k;
    
    vector<long long> v;
    FOR(i, 1, n) FOR(j, 1, m) v.push_back(1ll * i * j);

    sort(all(v));
    cout << v[k - 1];

    return 0;
}