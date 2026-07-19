#include <bits/stdc++.h>

using namespace std;

#define name "A"
#define ioname "remk"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(ioname".inp");
 
    int oo = 10;
    int n = Rand(1, 10);
    int k = Rand(1, oo);

    cout << n << ' ' << k << '\n';
    while (n--) cout << Rand(1, oo) << ' ';

    // long long l = Rand(1, 1e18);
    // long long r = Rand(l, min(l + 1e6, 1e18));

    // cout << l << ' ' << r << ' ' << Rand(1, 9) << ' ' << Rand(1, 12) << '\n';
}

int main()
{
    for (int i = 1; i <= ntest; i++)
    {
        GenTest();
        system(name".exe");
        system(name"_trau.exe");

        if (system("fc "ioname".out "ioname".ans") != 0)
        {
            cout << "Test: " << i << " WRONG!\n";
            return 0;
        }

        cout << "Test: " << i << " CORRECT!\n";
    }

    return 0;
}