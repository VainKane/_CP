#include <bits/stdc++.h>

using namespace std;

#define name "SODEP"

int n;

bool Check(int x)
{
    int s = 0;
    while (x)
    {
        s += x % 10;
        x /= 10;
    }

    return (s % 10 == 9);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    cout << Check(n);

    return 0;
}