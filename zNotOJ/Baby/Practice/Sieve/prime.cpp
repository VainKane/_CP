#include <bits/stdc++.h>

using namespace std;

bool Check(int x)
{
    for (int i = 2; i * i <= x; i++) if (x % i == 0) return false;
    return x > 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    while (cin >> n)
    {
        if (Check(n)) cout << n << " is prime!\n";
        else cout << n << " is not prime!\n";
    }

    return 0;
}