#include <bits/stdc++.h>

using namespace std;

int n;
int a[(int)1e5 + 10];
int m;

int pre[(int)1e5 + 10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];

        if (i > 0)
        {
            pre[i] = pre[i - 1] + a[i];
        } else pre[0] = a[0];
    }

    cin >> m;

    for (int i = 0; i < m; i++) 
    {
        int q;
        cin >> q;

        cout << lower_bound(pre, pre + n, q) - pre + 1 << '\n';
    }

    return 0;
}