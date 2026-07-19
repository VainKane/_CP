#include <bits/stdc++.h>

using namespace std;

#define name "20C"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int n = Rand(2, 1e2);
    int m = Rand(1, 2 * n);

    cout << n << ' ' << m << '\n';

    for (int i = 1; i <= n; i++)
    {
        int a = Rand(1, 1e9);
        cout << a << ' ';
    }
    cout << '\n';
    for (int i = 1; i <= m; i++)
    {
        int u = Rand(1, n);
        int v = Rand(1, n);
        while (v == u) v = Rand(1, n);

        cout << u << ' ' << v << '\n';
    }
}

int main()
{
    for (int itest = 1; itest <= ntest; itest++)
    {
        GenTest();
        system("./"name);
        system("./"name"_trau");

        if (system("diff "name".ans "name".out") != 0)
        {
            cout << "Test: " << itest << " WRONG!\n";
            return 0;
        }
        cout << "Test: " << itest << " CORRECT!\n";
    }
}