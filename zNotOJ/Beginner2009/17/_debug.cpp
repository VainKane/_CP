#include <bits/stdc++.h>

using namespace std;

#define name "17E"
int const ntest = 1e6;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int x = 1e3;

    int n = Rand(30, x);
    int m = Rand(30, x);
    int a = Rand(2, m / 10);
    int b = Rand(2, n / 10);
    cout << m << ' ' << n << '\n';

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int type = Rand(0, 4);
            
            if (type) cout << ' ';
            else cout << 'a';
        }
        cout << '\n';
    }
    cout << a << ' ' << b;
}

int main()
{
    for (int itest = 1; itest <= ntest; itest++)
    {
        GenTest();
        system(name".exe <"name".inp> "name".out");
        system(name"_trau.exe <"name".inp> "name".ans");

        if (system("fc "name".out "name".ans") != 0)
        {
            cout << "Test: " << itest << " WRONG!\n";
            return 0;
        }
        cout << "Test: " << itest << " CORRECT!\n";
    }
}