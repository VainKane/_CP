#include <bits/stdc++.h>

using namespace std;

#define name "business"
#define file "P"

int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");
 
    int n = Rand(3e5, 3e5); 
    int k = Rand(0, 1e4);

    cout << n << ' ' << k << '\n';
    for (int i = 1; i <= k; i++) cout << Rand(1, n) << ' ';
    cout << '\n';
    for (int i = 2; i <= n; i++)
    {
        cout << Rand(1, i - 1) << ' ' << i << '\n';
    }
}

int main()
{
    for (int i = 1; i <= ntest; i++)
    {
        GenTest();
        system(file".exe");
        system(file"_IT.exe");

        if (system("fc "name".out "name".ans") != 0)
        {
            cout << "Test: " << i << " WRONG!\n";
            return 0;
        }
        cout << "Test: " << i << " CORRECT!\n";
    }

    return 0;
}