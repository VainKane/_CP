#include <bits/stdc++.h>

using namespace std;

long long xa;
long long ya;

long long xb;
long long yb;

long long xc;
long long yc;

int main()
{
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    cout << xa + xc - xb << ' ';
    cout << ya + yc - yb;
}