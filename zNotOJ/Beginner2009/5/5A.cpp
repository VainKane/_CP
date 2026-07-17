#include <bits/stdc++.h>

using namespace std;

pair<long long, long long> a;
pair<long long, long long> b;
pair<long long, long long> c;

long long res;

long double Cal(pair<long long , long long> a, pair<long long, long long> b)
{
    return (long double)(1LL * a.first * b.second - b.first * a.second) / b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cout << fixed << setprecision(6);

    cin >> a.first >> b.first >> c.first;
    cin >> a.second >> b.second >> c.second;

    long double a1 = Cal(a, a);
    long double b1 = Cal(b, a);
    long double c1 = Cal(c, a);

    long double x =  Cal(a, b);
    long double y = Cal(b, b);
    long double z = Cal(c, b);

    long double m = Cal(a, c);
    long double n = Cal(b, c); 
    long double p = Cal(c, c);

    long double s1 = a1 + b1 + c1;
    long double s2 = x + y + z;
    long double s3 = m + n + p;

    long double mi = LONG_LONG_MAX;

    if (a1 >= 0 && b1 >= 0 && c1 >= 0)
    {
        mi = min(mi, s1);
    }
    if (x >= 0 && y >= 0 && z >= 0)
    {
        mi = min(mi, s2);
    }
    if (m >= 0 && n >= 0 && p >= 0)
    {
        mi = min(mi, s3);
    }

    if (mi == s1)
    {
        cout << a1 << ' ' << b1 << ' ' << c1;
        return 0;
    }
    if(mi == s2)
    {
        cout << x << ' ' << y << ' ' << z;
        return 0;
    }
    if (mi == s3)
    {
        cout << m << ' ' << n << ' ' << p;
    }

    return 0;
}