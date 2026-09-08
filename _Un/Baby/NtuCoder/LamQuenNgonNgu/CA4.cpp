#include <bits/stdc++.h>

using namespace std;

long long Solve(long long n, long long k)
{
    long long res;

    if (n <= k)
    {
        return k;
    }
    else
    {
        res = k * (n / k);

        while (res < n)
        {
            res += k;
        }
    }

    return res;
}

long long n;
long long k;


int main()
{
    cin >> n >> k;

    cout << Solve(n, k);

}
