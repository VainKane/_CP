#include <bits/stdc++.h>

using namespace std;

bool Check(bool cnt[], int a, int n, int k)
{
    if (k == n || (!cnt[a] && k == n - 1) ) return true;
    return false;
}

int t;

int n;
int m;
int k;

int a[(int)3e5 + 10];
int q[(int)3e5 + 10];

bool cnt[(int)3e5 + 10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> m >> k;

        memset(cnt, 0, sizeof cnt);

        for (int i = 0; i < m; i++) cin >> a[i];
        
        for (int i = 0; i < k; i++)
        {
            cin >> q[i];
            cnt[q[i]] = true;
        } 

        for (int i = 0; i < m; i++) cout << Check(cnt, a[i], n, k);

        cout << '\n';
    }

    return 0;
}