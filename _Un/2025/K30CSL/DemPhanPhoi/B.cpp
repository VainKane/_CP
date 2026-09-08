#include <bits/stdc++.h>

using namespace std;

int const N = 5e6 + 5;

int n;

int a[N];
int cnt[N];
bool used[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        cnt[a[i]]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (used[a[i]]) continue;
        if (!cnt[a[i]]) continue;
        
        cout << a[i] << ' ' << cnt[a[i]] << '\n';
        used[a[i]] = true;
    }

    return 0;
}