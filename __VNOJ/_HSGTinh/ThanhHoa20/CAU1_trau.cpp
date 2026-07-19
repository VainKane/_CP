#include <bits/stdc++.h>

using namespace std;

#define name "CAU1"

int x, y;

int Solve()
{
    int cnt = 0;
    for (int i = 1; i <= min(x, y); i++) 
    {
        if (x % i + y % i == 0)
        {
            cnt++;
            // cout << i << '\n';
        }
    }
    return cnt;
}

int main()
{
    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> x >> y;
    
    int res = Solve();
    cout << res;
    cerr << res << '\n';
}