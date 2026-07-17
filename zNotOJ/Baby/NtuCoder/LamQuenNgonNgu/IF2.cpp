#include <bits/stdc++.h>

using namespace std;

long long a;
long long b;

int main()
{
    cin >> a >> b;

    if (b == 0)
    {
        cout << -1;
    }
    else if (a % b == 0)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}