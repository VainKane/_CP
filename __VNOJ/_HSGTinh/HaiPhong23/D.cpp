#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 5;

int t;
int n, k;
int a[N];

map<int, bool> visted;

bool Solve()
{   
    visted.clear();
    for (int i = 1; i <= n; i++) visted[a[i]] = true;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] & 1)
        {
            if ((k - a[i]) & 1) continue;
            if (visted.count(k - a[i])) return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> n >> k;  
        for (int i = 1; i <= n; i++) cin >> a[i];
        cout << Solve();
    }

    return 0;
}