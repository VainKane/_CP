#include <bits/stdc++.h>

using namespace std;

#define name "NTH"
int const ntest = 1;
int const N = 1e5 + 5;

int a[N];

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int n = Rand(2, 2);
    int m = Rand(1, 10);

    cout << n << ' ' << m << '\n';

    int last = -1;
    for (int i = 1; i <= n; i++) 
    {
        last += Rand(1, 2);
        cout << last << ' ';
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