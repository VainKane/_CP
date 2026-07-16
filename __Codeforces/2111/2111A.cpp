#include <bits/stdc++.h>

using namespace std;

int Solve(int x)
{
    int res = 0;

    int a = 0;
    int b = 0;
    int c = 0;

    while (1)
    {
        if (a >= x || b >= x || c >= x) return res + 2;

        int mi = min({a, b, c});
        int ma = max({a, b, c});
        int mid = a + b + c - mi - ma;

        mi = mid * 2 + 1;

        a = mi;
        b = mid;
        c = ma;

        res++;
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        int x; cin >> x;
        cout << Solve(x) << '\n';
    }

    return 0;
}
