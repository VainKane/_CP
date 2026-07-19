#include <bits/stdc++.h>

using namespace std;

#define name "505D"
int const ntest = 1e4;

mt19937_64 rd(time(0));

long long Rand(long long l, long long r)
{
    return l + rd() * 1ll * rd() % (r - l + 1);
}

void GenTest()
{
    ofstream cout(name".inp");

    int n = Rand(2, 10);
    int m = Rand(1, 30);

    set<pair<int, int>> edges;
    while (m--)
    {
        int u = Rand(1, n - 1);
        edges.insert({u, Rand(u + 1, n)});
    }  

    m = edges.size();
    
    cout << n << ' ' << m << '\n';
    for (auto &p : edges) cout << p.first << ' ' << p.second << '\n';
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