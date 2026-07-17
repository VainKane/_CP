#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()

int const N = 2e5 + 5;

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
        int l, r;
        cin >> l >> r;

        vector<int> v;
        FOR(i, 1, l - 1) v.push_back(a[i]); 
        FOR(i, r + 1, n) v.push_back(a[i]);

        sort(all(v));
        cout << v[(v.size() + 1) / 2 - 1] << '\n';
    }

    return 0;
}