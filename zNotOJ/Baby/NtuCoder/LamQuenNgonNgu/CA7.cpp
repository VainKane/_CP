#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    cin >> n;

    cout << ((long long)(n - 2) * (n - 1) * (long long)n) / 6;
}