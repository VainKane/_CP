#include <bits/stdc++.h>

using namespace std;

#define name "29C"
int const N = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout (name".inp");

    int n = Rand(1, 1e4);
    int m = Rand(1, 1e4);
    cout << n << '\n';

    for (int i = 1; i <= n; i++)
    {
        int a = Rand(1, 1e9);
        cout << a << ' ';
    }
    cout << m << '\n';
    for (int i = 1; i <= m; i++)
    {
        int a = Rand(1, 1e9);
        cout << a << ' ';
    }
}

int main()
{
    for (int i = 1; i <= N ; i++)
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