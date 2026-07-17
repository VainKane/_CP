#include <bits/stdc++.h>

using namespace std;

#define name "SDB"

long long n;

bool isPrime(long long x)
{
    if (x <= 1) return false;
    for (long long i = 2; i * i <= x; i++)
    {
        if (x % i == 0) return false;
    }
    return true;
}

bool Check(long long x)
{
    int cnt = 0;
    for (long long i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            cnt++;
            if (i * i != x) cnt++;
        }
    }
    return cnt == 3;
}

void Solve(int x)
{
    long long k = x;
    while (!Check(k)) k++;

    // while ((int)sqrt(k) * 1ll * (int)sqrt(k) != k || !isPrime(sqrt(k))) k++;
    cout << k << ' ';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        Solve(x);
    }

    // for (long long i = 1; i <= n; i++) 
    // {
    //     int k = sqrt(i);
    //     if (k * k != i) continue; // i phai la chinh phuong
    //     if (!isPrime(k)) continue; // sqrt(i) phai la nguyen to
    //     // if (!Check(i)) continue; // thoa 2 dk tren ma khong phai la so co 3 uoc

    //     cout << i << '\n';
    // }

    // Solve(1e9);    

    return 0;
}