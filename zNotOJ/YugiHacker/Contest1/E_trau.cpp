#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()

int const N = 1e5 + 5;

int n, q;
int a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];

    while (q--)
    {
        int x, k;
        cin >> x >> k;

        vector<long long> v;
        FOR(i, 1, n) v.push_back(abs(1ll * a[i] - x));
        sort(all(v));
        cout << v[k - 1] << '\n';
    }

    return 0;
}