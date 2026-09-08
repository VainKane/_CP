#include <bits/stdc++.h>

using namespace std;

#define name "19C"
int const ntest = 10;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int a[4];

    int s = 0;
    int max = 10;

    for (int i = 1; i <= 3; i++) 
    {
        a[i] = Rand(1, max);
        cout << a[i] << ' ';
    }
    
    cout << '\n';
    for (int i = 1; i <= 3; i++)
    {
        int x = Rand(0, a[i]);
        cout << x << ' ';
        s += x;
    }

    cout << '\n';
    for (int i = 1; i <= 2; i++)
    {
        int x = Rand(0, s);
        cout << x << ' ';
        s -= x;
    }
    cout << s;
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