#include <bits/stdc++.h>

using namespace std;

bool Check3(int n, int d)
{
    return (d % 3 == 0 || n >= 3);
}

bool Check5(int d)
{
    return (d == 0 || d == 5);
}

bool Check7(int n, int d)
{
    return (d == 7 || n >= 3);
}

bool Check9(int n, int d)
{
    return ( (d % 3 == 0 && n >= 3) || (n >= 6) || d % 9 == 0);
}
    

int t;

int n;
int d;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> d;

        cout << 1 << ' ';
        if (Check3(n, d)) cout << 3 << ' ';
        if (Check5(d)) cout << 5 << ' ';
        if (Check7(n, d)) cout << 7 << ' ';
        if (Check9(n, d)) cout << 9 << ' ';

        cout << '\n';
    }

    return 0;
}