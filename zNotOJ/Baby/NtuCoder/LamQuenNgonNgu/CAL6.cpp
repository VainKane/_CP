#include <bits/stdc++.h>

using namespace std;

int a;
int b;

int main()
{
    cin >> a >> b;

    cout << fixed << setprecision(2);

    cout << a / b << '\n';
    cout << a % b << '\n';
    cout << (long double)a / b;
}