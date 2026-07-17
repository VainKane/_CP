#include <bits/stdc++.h>

using namespace std;

#define name "remainder"

int main()
{
    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    long long a, b;
    cin >> a >> b;
    cout << (a % b + abs(b)) % b;
}