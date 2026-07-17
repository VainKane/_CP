#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 5;

int t;
int n, k; 
int a[N];  

bool Solve()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (a[i] + a[j] != k) continue;
            if (a[i] % 2 + a[j] % 2 == 1) 
            {
                // cerr << "\nresult: " << a[i] << ' ' << a[j] << ' ';
                return true;
            }
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
        bool res = Solve();
        cout << res;
        cerr << res;
    }
    cerr << '\n';

    return 0;
}