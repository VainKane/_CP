#include <bits/stdc++.h>

using namespace std;

int Spilt(long long n)
{
    int r1 = n % 10;
    n /= 10;
    int r2 = n % 10;
    

    return (r2 * 10) + r1;
}

int a;
int b;

int main()
{
    cin >> a >> b;

    if (Spilt((long long)a * b) % 3 == 0)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}