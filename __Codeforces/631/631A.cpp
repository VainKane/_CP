#include <bits/stdc++.h>

using namespace std;

int const N = 1009;

int n;
int s1 = 0;
int s2 = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        s1 |= x;
    }
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        s2 |= x;
    }

    cout << s1 + s2;

    return 0;
}