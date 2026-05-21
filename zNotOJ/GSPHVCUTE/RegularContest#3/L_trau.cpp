#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()
#define name "sort"

int const N = 5009;

int n;
int a[N], c[N];

long long pre[N];

vector<int> vals;

int GetSum(int l, int r)
{
    if (l == r) return 0;
    if (l > r) swap(l, r);
    return pre[r - 1] - pre[l - 1];
}

int GetGoal(int x)
{
    return lower_bound(all(vals), x) - vals.begin() + 1;
}

long long Cal()
{
    long long res = 0;
    FOR(i, 1, n) res += GetSum(i, GetGoal(a[i]));
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n;
    FOR(i, 1, n) cin >> a[i], vals.push_back(a[i]);
    FOR(i, 1, n - 1) cin >> c[i];

    sort(all(vals));
    FOR(i, 1, n - 1) pre[i] = pre[i - 1] + c[i];

    cout << Cal() << '\n';

    int q; cin >> q;
    while (q--)
    {
        int type, x, y;
        cin >> type >> x >> y;

        if (type == 1) swap(a[x], a[y]);
        else 
        {
            c[x] = y;
            FOR(i, 1, n - 1) pre[i] = pre[i - 1] + c[i];
        }

       cout << Cal() << '\n';
    }

    return 0;
}