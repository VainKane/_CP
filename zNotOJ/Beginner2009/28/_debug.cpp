#include <bits/stdc++.h>

using namespace std;

int const ntest = 1e4;
#define name "28D"

mt19937 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1); 
}

void GenTest()
{
    ofstream cout(name".inp");

    int n = Rand(1, 100);
    cout << n << '\n';

    for (int i = 1; i <= n; i++)
    {
        int a = Rand(1, 100);
        cout << a << ' ';
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

    return 0;
}