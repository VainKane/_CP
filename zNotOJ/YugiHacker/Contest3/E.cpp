#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define F first
#define S second

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 2e5 + 5;
long long const oo = 8e18;

int n;
pair<int, int> a[N];

long long Dist(pair<int, int> a, pair<int, int> b)
{
    int x = a.F - b.F;
    int y = a.S - b.S;

    return (long long)x * x + 1ll * y * y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("E.inp", "r", stdin);

    cin >> n;
    FOR(i, 1, n) cin >> a[i].F >> a[i].S;

    sort(a + 1, a + n + 1);

    set<pair<int, int>> st;
    long long res = oo;
    int idx = 1;
    
    FOR(i, 1, n)
    {
        while (a[i].F - a[idx].F > res && idx < i)
        {
            if (!st.empty()) st.erase(a[idx]);
            idx++;
        }

        while (a[i].F - a[idx].F <= res && idx < i)
        {
            st.insert(a[idx]);
            for (auto &pos : st) mini(res, Dist(a[i], pos));
            idx++;
        }

        st.insert(a[i]);
    }

    cout << res;

    return 0;
}