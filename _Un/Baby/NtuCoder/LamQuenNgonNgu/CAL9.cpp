#include <bits/stdc++.h>

using namespace std;

int n;
int m;

int main()
{
    cin >> n >> m;

    cout << ((m - 1) * m ) / 2 + (n - 1) * n + 2 * m * n; 
}