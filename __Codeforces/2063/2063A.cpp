#include <bits/stdc++.h>

using namespace std;

int t;
int l;
int r;

int main()
{
    cin >> t;

    while (t--)
    {
        cin >> l >> r;

        if (l * r == 1) cout << 1 << '\n';
        else cout << r - l << '\n';
    }

    return 0;
}