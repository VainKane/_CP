#include <bits/stdc++.h>

using namespace std;

int GCD(int a, int b)
{
    if (a % b == 0) return b;

    int r = a % b;

    while (r)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

long long LCM(int a, int b)
{
    return (long long)a * b / GCD(a, b);
}

int n;
int p;
int q;
int r;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (cin >> n)
    {
        cin >> p >> q >> r;
        
        int s1 = n / LCM(p, q);
        int s2 = n / LCM(q, r);
        int s3 = n / LCM(r, p);
        int s4 = n / LCM(LCM(p, q), r);

        cout << s1 + s2 + s3 - 3 * s4 << '\n';
    }

    return 0;
}