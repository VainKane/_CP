#include <bits/stdc++.h>

using namespace std;

#define name "E"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

bool Prime(int x)
{
    if (x <= 1) return false;
    for (int i = 2; i <= sqrt(x); i++) if (x % i == 0) return false;
    return true;
}

void GenTest()
{
    ofstream cout(name".inp");
    int n = Rand(1, 3e5);
    int oo = 1e3;

    cout << n << '\n';
    while (n--)
    {
        int x = 2;
        while (Prime(x)) x = Rand(2, oo);
        cout << x << ' ';
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