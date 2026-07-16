#include <bits/stdc++.h>

using namespace std;

#define name "C"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int n = Rand(5, 1e2);
    int m = Rand(n, 1e5);

    int k = Rand(1, 1e2);
    int s = Rand(1, n);
    int t = s;
    while (t == s) t = Rand(1, n);

    int a[n + 1];
    for (int i = 1; i <= n; i++) a[i] = i;

    random_shuffle(a + 1, a + n + 1);

    cout << n << ' ' << m << ' ' << k << ' ' << s << ' ' << t << '\n';

    for (int i = 2; i <= n; i++)
    {       
        cout << a[i] << ' ' << a[Rand(1, i - 1)] << ' ' << Rand(1, 1000) << '\n';
    }

    for (int i = 1; i <= m - n + 1; i++)
    {
        cout << a[Rand(n / 2, n)] << ' ' << a[Rand(n / 5, n / 2 - 1)] << ' ' << Rand(1, 1000) << '\n';
    }

    for (int i = 1; i <= k; i++)
    {
        cout << a[Rand(n / 2, n)] << ' ' << a[Rand(n / 5, n / 2 - 1)] << ' ' << Rand(1, 1000) << '\n';
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