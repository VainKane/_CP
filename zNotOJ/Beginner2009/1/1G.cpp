#include <bits/stdc++.h>

using namespace std;

long long n;
long long a;
long long b;

long long s = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> a >> b;

    for (long long i = a; i <= b; i++)
    {
        long long k = n / i;

        long long iMax = min(n / k, b);
        s += (iMax - i + 1) * k;

        i = iMax;
    }

    cout << s;
}