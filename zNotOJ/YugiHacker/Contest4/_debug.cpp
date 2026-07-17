#include <bits/stdc++.h>

using namespace std;

#define name "B"
#define ioname "minprod"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(ioname".inp");

    int n = Rand(2, 1000);
    int oo = 10;
        
    cout << n << '\n';
    for (int i = 1; i <= n; i++) cout << Rand(1, oo) << ' ';
    cout << '\n';
    while (n--) cout << Rand(1, oo) << ' ';
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