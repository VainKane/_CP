#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()

int const N = 5e4 + 5;

int n, k;
int a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];

    vector<int> v;
    FOR(i, 1, n) FOR(j, i + 1, n) if (a[i] > a[j]) v.push_back(a[i] - a[j]);

    sort(all(v));
    cout << v[k - 1];

    return 0;
}