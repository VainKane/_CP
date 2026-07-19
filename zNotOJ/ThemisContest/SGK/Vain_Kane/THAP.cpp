#include <bits/stdc++.h>

using namespace std;

#define name "THAP"

int n;

void Solve(int n, char a, char b, char c)
{
    if (n == 1)
    {
        cout << a << "->" << c;
        cout << '\n';
        return;
    }

    Solve(n - 1, a, c, b);
    Solve(1, a, b, c);
    Solve(n - 1, b, a, c);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    Solve(n, 'A', 'B', 'C');

    return 0;
}