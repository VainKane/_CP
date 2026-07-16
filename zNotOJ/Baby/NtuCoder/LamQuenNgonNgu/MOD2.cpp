#include <bits/stdc++.h>

using namespace std;

long long a;
long long b;
long long c;

int main()
{
    cin >> a >> b;
    cin >> c;

    cout << ( (a % c) * (b % c) ) % c;
}