#include <bits/stdc++.h>

using namespace std;

#define name "41A"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int n = Rand(1e2, 1e2);
    int m = Rand(n, 1e2);
    int k = Rand(1e2, 1e2);

    int a[n + 1];
    for (int i = 1; i <= n; i++) a[i] = i;
    random_shuffle(a + 1, a + n + 1); 

    cout << n << ' ' << m << '\n';
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    for (int i = 1; i <= m - n; i++) cout << a[Rand(1, n)] << ' ';

    cout << '\n';
    for (int i = 1; i <= n; i++) cout << Rand(1, 1e7) << ' ';

    cout << k << '\n';
    for (int i = 1; i <= n; i++)
    {
        int l = Rand(1, n);
        int r = Rand(l, n);
        int c = Rand(1, 1e9);

        cout << l << ' ' << r << ' ' << c << '\n';
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
}