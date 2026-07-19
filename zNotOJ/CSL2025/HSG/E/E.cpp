#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define sz(v) ((int)v.size())
#define F first
#define S second

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 1e5 + 5;

int n, k, d;
pair<int, int> a[N];
long long pre[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k >> d;
    FOR(i, 1, n) cin >> a[i].S >> a[i].F;

    sort(a + 1, a + n + 1);

    multiset<int> ms;

    long long sum = 0, res = -1;

    int j = 1;    
    FOR(i, 1, n)
    {
        ms.insert(a[i].S);
        sum += a[i].S;

        int l = lower_bound(a + 1, a + i, make_pair(a[i].F - d, 0)) - a;
        while (j < l)
        {
            auto it = ms.find(a[j].S);
            if (it != ms.end()) ms.erase(it);
            sum -= *it;
            j++;
        }
        if (sz(ms) > k) 
        {
            auto it = ms.find(*ms.rbegin());
            ms.erase(it);
            sum -= *it;
        }
        if (sz(ms) == k) maxi(res, sum);
    }    

    cout << res;

    return 0;
}