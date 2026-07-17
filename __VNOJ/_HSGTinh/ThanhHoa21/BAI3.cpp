#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define all(v) v.begin(), v.end()
#define name "BAI3"

int const N = 1e5 + 5;

int n, k;
multiset<int> a;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> k;
    FOR(i, 1, n)
    {
        int x; cin >> x;
        a.insert(x);
    }

    long long res = 0;

    while (!a.empty())
    {   
        int last = *a.rbegin();
        a.erase(prev(a.end()));

        res += last;

        bool processing = true;
        while (processing)
        {
            processing = false;
            auto it = a.upper_bound(last - k);
            if (it != a.begin())
            {
                it--;
                last = *it;
                a.erase(it);
                processing = true;
            }
        }
    }

    cout << res;

    return 0;
}
