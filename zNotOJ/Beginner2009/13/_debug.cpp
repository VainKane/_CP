#include <bits/stdc++.h>

using namespace std;

#define name "13G"
int const ntest = 1e4;
int const N = 5009;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

int a[N];

void GenTest()
{
    ofstream cout(name".inp");

    int n = Rand(1, 1e2, 1e3);
    int k = Rand(n / 2, n);

    int sg = Rand(1e8, 1e9);
    int l = 1;
    int r = sg;

    cout << n << ' ' << k << '\n';
    cout << l << ' ' << r << '\n';

    for (int i = 1; i <= n; i++)
    {
        a[i] = Rand(a[i - 1] + 1, min(a[i - 1] + 25, sg));
    }
    
    sg = Rand(a[n] + a[1] + l, a[n] + a[1] + r);
    cout << sg << '\n';

    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
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