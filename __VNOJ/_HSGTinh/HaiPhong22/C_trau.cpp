#include <bits/stdc++.h>

using namespace std;

#define name "C"

int const N = 25;

int n;
long long x;

int p[N];
int t[N];

void Solve()
{
    long long eggs = 0;
    long long res = 0;

    while (eggs < x)
    {
        res++;
        for (int i = 1; i <= n; i++) 
        {
            if (res < p[i]) continue;
            eggs += ((res - p[i]) % t[i] == 0);
        }
    }

    cout << res;
    // cerr << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen(name".inp", "r", stdin);
    // freopen(name".ans", "w", stdout);

    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i] >> t[i];
    }

    Solve();

    return 0;
}