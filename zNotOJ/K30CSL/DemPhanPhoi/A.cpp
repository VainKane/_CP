#include <bits/stdc++.h>

using namespace std;

int const N = 1e7 + 5;

int n;
bool cnt[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        cnt[x] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!cnt[i])
        {
            cout << i;
            return 0;
        }
    }

    return 0;
}