#include <bits/stdc++.h>

using namespace std;

#define name "QKGRAPH"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int m = Rand(1, 2000);
    int n = Rand(550, 770);
    int k = Rand(1, min(m ,n));

    cout << m << ' ' << n << ' ' << k << '\n';

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << Rand(-1e9, 1e9) << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    for (int i = 1; i <= ntest; i++)
    {
        GenTest();
        system(name".exe");
        system(name"_trau.exe");

        if (system("fc "name".out "name".ans") != 0)
        {
            cout << "Test: " << i << " WRONG!\n";
            return 0;
        }
        cout << "Test: " << i << " CORRECT!\n";
    }
}