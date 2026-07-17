#include <bits/stdc++.h>

using namespace std;

#define name "FAIR"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int oo = 1e9;
    int n = Rand(1, 300);
    int q = Rand(1, 1e2);

    int a[n + 1];

    for (int i = 1; i <= n; i++) a[i] = Rand(1, oo);
    
    cout << n << ' ' << q << '\n';
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << '\n';
    while (q--) cout << min(a[Rand(1, n)], a[n] - 1) << ' ';
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