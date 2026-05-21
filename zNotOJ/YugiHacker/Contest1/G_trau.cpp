#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())

int const N = 2e5 + 5;

int n, q;
int a[N];

bool Check(vector<int> &v)
{
    if (sz(v) == 1) return true;
    sort(all(v));

    int d = v[1] - v[0];
    FOR(i, 1, sz(v) - 1) if (v[i] - v[i - 1] != d) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("G.inp", "r", stdin);
    freopen("G.ans", "w", stdout);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        vector<int> v;
        FOR(i, l, r) v.push_back(a[i]);
        cout << (Check(v) ? "YES\n" : "NO\n");
        if (q == 1) cerr << (Check(v) ? "YES\n" : "NO\n");
    }

    return 0;
}