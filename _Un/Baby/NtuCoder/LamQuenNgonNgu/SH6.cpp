#include <bits/stdc++.h>

using namespace std;

long long n;
long long res;

long long f0 = 1;
long long f1 = 1;
long long nextFibo;

int main()
{
    cin >> n;

    while (true)
    {
        nextFibo = f1 + f0;
        f0 = f1;
        
        if (nextFibo > n)
        {
            break;
        }
        
        f1 = nextFibo;
    }

    cout << f1;

    return 0;
}