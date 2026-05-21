#include <bits/stdc++.h>

using namespace std;

int n;
int m;

pair<int, int> a[(int)1e5 + 10];

bool Check(int d, int n)
{
    int pos = a[0].first + d;
    n--;

    for (int i = 0; i < m; i++)
    {
        pos = max(pos, a[i].first);

        while (pos <= a[i].second)
        {
            n--;
            pos += d;

            if (n == 0) return true;
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    sort(a, a + m);

    int l = 1; 
    int r = 1e9;
    int mid;
    int res;

    while (l <= r)
    {
        mid = (l + r) / 2;

        if (Check(mid, n))
        {
            res = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    cout << res;

    return 0;
}