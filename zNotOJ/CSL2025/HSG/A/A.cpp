#include <bits/stdc++.h>

using namespace std;

int n;
int x;
int y;

int main()
{
    cin >> n >> x >> y;

    if (n < 5) cout << min(n * x, 5 * y);
    else cout << n * min(x, y);
    return 0;
}
