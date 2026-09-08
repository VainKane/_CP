#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 1e5 + 5;

int n, q;
int a[N];

int Count(long long l, long long r)
{
    return upper_bound(a + 1, a + n + 1, r) - lower_bound(a + 1, a + n + 1, l);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
    
    sort(a + 1, a + n + 1);
    
    FOR(i, 1, q) 
    {
        int x, k;
        cin >> x >> k;

        long long l = 0;
        long long r = 4e9;
        long long rad = r;

        while (l <= r)
        {
            long long mid = (l + r) >> 1;
            if (Count(x - mid, x + mid) >= k)
            {
                rad = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }

        cout << rad << '\n';
    }

    return 0;
}