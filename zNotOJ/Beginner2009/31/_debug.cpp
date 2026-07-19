#include <bits/stdc++.h>

using namespace std;

#define name "31C"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout (name".inp");

    int n = Rand(1, 10);
    int m = Rand(1, 20);
    int z = Rand(1, 5);
    cout << n << ' ' << m << ' ' << z << '\n';

    for (int i = 1; i <= z; i++)
    {
        int a = Rand(1, n);
        int b = Rand(a, n);
        int w = Rand(1, m);

        cout << a << ' ' << b << ' ' << w << '\n';
    }
}

int main()
{
    for (int itest = 1; itest <= ntest; itest++)
    {
        GenTest();
        system(name".exe");
        system(name"_trau.exe");

        if (system("fc "name".ans "name".out") != 0)
        {
            cout << "Test: " << itest << " WRONG!\n";
            return 0;
        }
        cout << "Test: " << itest << " CORRECT!\n";
    }
}