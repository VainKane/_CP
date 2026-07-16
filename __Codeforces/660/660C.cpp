#include <bits/stdc++.h>

using namespace std;

int const N = 3e5 + 5;

int n, k;
int a[N];
int pre[N];

void Print(int left, int right)
{
    cout << right - left + 1 << '\n';

    for (int i = 1; i <= n; i++)
    {
        if (i >= left && i <= right) a[i] = 1;
        cout << a[i] << ' ';
    }
}

void Solve1()
{
    int left = 1;
    int right = 0;

    for (int i = 1; i <= n; i++)
    {
        int l = i;
        int r = n;
        int bound = i;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            
            if (pre[mid] - pre[i - 1] <= k)
            {
                bound = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }

        if (bound == i && !a[i] && !k) continue;

        if (bound - i > right - left) 
        {
            left = i;
            right = bound;
        }
    }

    Print(left, right);    
}

void Solve2()
{
    int left = 1;
    int right = 0;

    int r = 1;

    for (int l = 1; l <= n; l++)
    {
        while (pre[r + 1] - pre[l - 1] <= k && r < n) r++;
        if (l == r && !a[l] && !k) continue;
        if (right - left < r - l)
        {
            left = l;
            right = r;
        }
    }

    Print(left, right);    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + (a[i] ^ 1);

    Solve2();

    return 0;
}