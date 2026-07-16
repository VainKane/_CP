#include <bits/stdc++.h>

using namespace std;

bool Check(int n, int m)
{
    if (n == m) return true;
    if (n % 3 != 0) return false;

    return Check(n / 3, m) | Check((2 * n) / 3, m);
}


int n;
int m;
int t;

int main()
{
    cin >> t;

    while (t--)
    {
        cin >> n >> m;
        if (Check(n, m)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}