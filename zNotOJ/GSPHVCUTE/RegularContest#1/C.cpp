#include <bits/stdc++.h>

using namespace std;

#define name "quyhoachdong"

int a, b, c, m;

bool Check()
{
    if (a * b * c == 0 || m < 3) return false;
    return (a + b + c >= m);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    while (cin >> a)
    {
        cin >> b >> c >> m;
        cout << (Check() ? "No " : "Yes ");
    }

    return 0;
}