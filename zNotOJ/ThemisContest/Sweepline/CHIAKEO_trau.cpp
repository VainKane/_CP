#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define F first
#define S second
#define name "CHIAKEO"

int const N = 1e5 + 5;

int n, m;
int a[N];

pair<int, int> res;

void Update(int l, int r)
{
    FOR(i, l, r) 
    {
        if (++a[i] > res.F) res = {a[i], 1};
        else if (a[i] == res.F) res.S++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n >> m;
    while (m--)
    {
        int l, r;
        cin >> l >> r;

        if (l <= r) Update(l, r);
        else 
        {
            Update(l, n);
            Update(1, r);
        }
    }

    cout << res.F << ' ' << res.S;

    return 0;
}