#include <bits/stdc++.h>

#define min(a, b) ((a < b) ? a : b)

using namespace std;

int t;

int m;
int a;
int b;
int c;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> m >> a >> b >> c;

        cout << min(a, m) + min(b, m) + min(2 * m - min(a, m) - min(b, m), c) << '\n';
    }

    return 0;
}