#include <bits/stdc++.h>

using namespace std;

long long xa;
long long ya;

long long xb;
long long yb;

long long xc;
long long yc;

long double ab;
long double bc;
long double ac;

long double p;

int main()
{
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    cout << abs((xb - xa) * (yc - ya) - (xc - xa) * (yb - ya));
}