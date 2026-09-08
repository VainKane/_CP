#include <bits/stdc++.h>

using namespace std;

double const pi = 3.14;

double a, b;

double Solve()
{
    double rec = a * b;
    double cir = (b / 2) * (b / 2) * pi;

    double res = rec - cir;
    return (round(res * 100)) / 100;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cout << fixed << setprecision(2);

    cin >> a >> b;
    cout << Solve();

    return 0;
}