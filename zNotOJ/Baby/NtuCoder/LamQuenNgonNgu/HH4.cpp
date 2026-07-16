#include <bits/stdc++.h>

using namespace std;

long long ux;
long long uy;

long long vx;
long long vy;

long double cosVector;

int main()
{
    std::cin >> ux >> uy >> vx >> vy;

    cosVector = ((long double)ux * uy + (long double)vx * vy) / ( (long double)sqrt(ux * ux + uy * uy) * sqrt(vx * vx + vy * vy) );

    if (cosVector > 0 && cosVector < 1)
    {
        cout << "NHON";
    }
    else if (cosVector == 0)
    {
        cout << "VUONG";
    }
    else
    {
        cout << "TU";
    }
}