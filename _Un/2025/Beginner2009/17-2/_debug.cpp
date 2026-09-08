#include <bits/stdc++.h>

using namespace std;

#define name "17-2B"
int const ntest = 1e6;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int n = Rand(1, (int)20);
    int m = Rand(1, (int)20);
    cout << n << ' ' << m <<'\n';

    for (int i = 1; i <= n; i++)
    {
        long long a = Rand(1, 1e18);
        cout << a << ' ';
    }
    cout << '\n';
    for (int i = 1; i <= m; i++)
    {
        long long t = Rand(1, 1e18);
        int l = Rand(1, n);
        int r = Rand(l, n);

        cout << t << ' ' << l << ' ' << r << '\n';
    }
}

int main()
{
    for (int itest = 1; itest <= ntest; itest++)
    {
        GenTest();
        system("./" name);
        system("./" name "_trau");

        if (system("diff " name ".ans " name ".out") != 0)
        {
            cout << "Test: " << itest << " WRONG!\n";
            return 0;
        }
        cout << "Test: " << itest << " CORRECT!\n";
    }
}