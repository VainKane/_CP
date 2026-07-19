#include <bits/stdc++.h>

using namespace std;

long long xA;
long long yA;

long long xB;
long long yB;

long long xC;
long long yC;

int main()
{
    cin >> xA >> yA >> xB >> yB >> xC >> yC;

    if ((long double)(xC - xB) / (xA - xB) == (long double)(yC - yB) / (yA - yB))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}