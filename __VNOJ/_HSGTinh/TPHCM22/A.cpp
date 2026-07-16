#include <bits/stdc++.h>

using namespace std;

int const N = 1009;

int n;
int a[N][N];

int cnt = 0;

bool Solve()
{
    for (int i = 1; i <= n; i++)
    {
        int s = 0;
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] < 0) return false;
            if (i != j) s += a[i][j];
        }   

        if (a[i][i] < s) return false;
        cnt += (a[i][i] > s);
    }
    
    return cnt > 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> a[i][j];

    if (!Solve()) cout << "NO";
    else
    {
        cout << "YES\n";
        cout << cnt;
    }

    return 0;
}