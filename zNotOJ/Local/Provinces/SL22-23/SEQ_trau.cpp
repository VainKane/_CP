#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 5;

int n;
int a[N];

long long p[N];
long long res = -1e18;

long long GetSum(int l, int r)
{
    return p[r] - p[l - 1];
}

int l, r, u, v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) p[i] = p[i - 1] + a[i];

    for (int l1 = 1; l1 <= n; l1++)
    {
        for (int r1 = l1 + 2; r1 <= n; r1 += 3)
        {
            for (int l2 = 1; l2 < l1; l2++)
            {
                for (int r2 = l2 + 2; r2 < l1; r2 += 3)
                {
                    // if ((r2 - l2 + 1) % 3 != 0) continue;
                    if (res < GetSum(l1, r1) + GetSum(l2, r2)) 
                    {
                        l = l1;
                        r = r1;
                        u = l2;
                        v = r2;
                    }

                    res = max(res, GetSum(l1, r1) + GetSum(l2, r2));
                }
            }

            for (int l2 = r1 + 1; l2 <= n; l2++)
            {
                for (int r2 = l2 + 2; r2 <= n; r2 += 3)
                {
                    // if ((r2 - l2 + 1) % 3 != 0) continue;
                    if (res < GetSum(l1, r1) + GetSum(l2, r2)) 
                    {
                        l = l1;
                        r = r1;
                        u = l2;
                        v = r2;
                    }
                    res = max(res, GetSum(l1, r1) + GetSum(l2, r2));
                }
            }
        }
    }

    cout << res;
    // cout << '\n' << l << ' ' << r << " | " << u << ' ' << v;
    
    return 0;
}