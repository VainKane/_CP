#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
    cin >> n;

    if ((long long)sqrt(n) * (long long)sqrt(n) == n)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}