#include <bits/stdc++.h>

using namespace std;

int m, k, a1, ak;

bool Check(int x)
{
    int cntK = min(m / k, ak + x);
    x -= max(cntK - ak, 0);

    return m <= cntK * k + a1 + x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> m >> k >> a1 >> ak;
        
        int l = 0;
        int r = m;
        int res = r;

        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (Check(mid))
            {
                res = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }

        cout << res << '\n';
    }

    return 0;
}