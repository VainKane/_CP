#include <bits/stdc++.h>

using namespace std;

#define name "15F"
int const ntest = 1e6;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int n = Rand(1, (int)1e5);
    cout << n << '\n';

    for (int i = 1; i <= n; i++)
    {
        int l = Rand(1, 10);

        for (int j = 1; j <= l; j++)
        {
            int a = Rand('a', 'z');
            cout << (char)a;
        }
        cout << '\n';
    }

    int t = Rand(1, (int)1e5);
    cout << t << '\n';
    for (int i = 1; i <= t; i++)
    {
        int l = Rand(1, 5);
        for (int j = 1; j <= l; j++)
        {
            int a = Rand('a', 'z');
            cout << (char)a;
        }
        cout << '\n';
    }
}

int main()
{
    for (int itest = 1; itest <= ntest; itest++)
    {
        GenTest();
        system(name".exe");
        system(name"_trau.exe");

        if (system("fc "name".out "name".ans") != 0)
        {
            cout << "Test:  " << itest << " WRONG!\n";
            return 0;
        }
        cout << "Test: " << itest << " CORRECT!\n";
    }
}