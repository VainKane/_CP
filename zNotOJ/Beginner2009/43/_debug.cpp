#include <bits/stdc++.h>

using namespace std;

#define name "43D"
int const ntest = 10;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int n = Rand(1, 1e2);
    cout << n << '\n';

    int x = 100;

    int last = -x;

    while (n--) 
    {
        last = Rand(last + 1, last + 5);
        cout << last << ' ' << Rand(-x, x) << '\n';
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