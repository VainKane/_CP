#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()
#define F first
#define S second

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 1e5 + 5;

int n, m;
pair<int, int> a[N];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i].F >> a[i].S;

    int res = 0;

    int curR = 0;

    int q; cin >> q;
    while (q--)
    {
        int l; cin >> l;
        int id = upper_bound(all(vals), l) - vals.begin();
        
        if (curR < l)
        {
            if (pre[id] < l) 
            {
                cout << -1;
                return 0;
            }

            curR = pre[id];
            res++;
        }
    }

    cout << res - 1;

    return 0;
}