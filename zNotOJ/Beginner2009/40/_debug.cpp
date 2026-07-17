#include <bits/stdc++.h>

using namespace std;

#define name "40C"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");
    int n = Rand(1, 1e2);
    int k = Rand(1, __builtin_popcount(n));

    cout << n << ' ' << k << '\n';
    cout << "0 0";
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
        cout << " Test: " << i << " CORRECT!\n";
    }
}