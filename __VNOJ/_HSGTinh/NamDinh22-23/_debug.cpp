#include <bits/stdc++.h>

using namespace std;

#define name "CSBN"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int n = Rand(1, 1e4);
    cout << n << '\n';

    vector<int> a;

    for (int i = 1; i <= n; i++)
    {
        int type = Rand(1, 1000);
        if (type == 1) 
        {
            int m = Rand(1, 1e9);
            a.push_back(m);
            cout << m << ' ';
        }
        else if (a.size()) cout << a[Rand(0, a.size() - 1)] << ' ';
        else i--;
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