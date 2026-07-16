#include <bits/stdc++.h>

using namespace std;

#define name "graph"

struct Edge
{
    int u, v;
};

int k, d;

int n = 0;
vector<Edge> a;

void Print()
{
    cout << n << ' ' << a.size() << '\n';
    for (auto e : a) cout << e.u << ' ' << e.v << '\n';
}

void Create(int x, int y)
{
    int l = n + 1;
    for (int i = 1; i <= d - 2; i++) a.push_back({++n, n + 1}); // under path
    int r = ++n;

    for (int i = 1; i <= x; i++) a.push_back({l, ++n});
    for (int i = 1; i <= y; i++) a.push_back({r, ++n}); 
}

void Solve()
{
    while (k)
    {
        int t = sqrt(k);
        Create(t, t);
        k -= 1 * t * t;
    }
}

void Solve2()
{
    while (k)
    {
        int t = 2;
        int center = ++n;

        while ((t + 1) * t / 2 <= k) t++;
        for (int i = 1; i <= t; i++) a.push_back({center, ++n});

        k -= t * (t - 1) / 2;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> d >> k;
    
    if (d > 2) Solve();
    else Solve2();

    Print();

    return 0;
}