#include <bits/stdc++.h>

using namespace std;

#define name "5232"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int oo = 10;
    int n = Rand(1, 10);
    
    cout << n << '\n';
    while (n--)
    {
        int x1 = Rand(-oo, oo);
        int y1 = Rand(-oo, oo);
        cout << x1 << ' ' << y1 << ' ' << Rand(x1, oo) << ' ' << Rand(y1, oo) << '\n';
    }
}

int main()
{
    for (int i = 1; i <= ntest; i++)
    {
        GenTest();
        system(name".exe <"name".inp> "name".out");
        system(name"_trau.exe <"name".inp> "name".ans");

        if (system("fc "name".out "name".ans") != 0)
        {
            cout << "Test: " << i << " WRONG!\n";
            return 0;
        }
        cout << "Test: " << i << " CORRECT!\n";
    }

    return 0;
}