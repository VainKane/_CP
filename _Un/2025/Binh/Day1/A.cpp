#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()

int const N = 3e5 + 5;

int n;
pair<int, int> a[N], b[N];

int Cal(pair<int, int> a[], pair<int, int> l, pair<int, int> r)
{
    int res = upper_bound(a + 1, a + n + 1, r) - lower_bound(a + 1, a + n + 1, l);
    return res < 0 ? 0 : res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) 
    {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
        b[i] = {y, x};
    }

    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);

    int q; cin >> q;
    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int res = 0;

        res += Cal(a, {x1, y1}, {x1, y2});
        if (x1 != x2) res += Cal(a, {x2, y1}, {x2, y2});

        x1++; x2--;

        res += Cal(b, {y1, x1}, {y1, x2});
        if (y1 != y2) res += Cal(b, {y2, x1}, {y2, x2});

        cout << res << '\n';
    }

    return 0;
}