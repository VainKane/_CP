#include <bits/stdc++.h>

using namespace std;

bool Check(int x, int y)
{
    if (y == x + 1) return true;
    int a = x / 9;
    for (int i = 0; i <= a; i++)
    {
        if (x - i * 9 + 1 == y) return true;
    }

    return false;
}

int t;

int x;
int y;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> x >> y;

        if (Check(x, y)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}