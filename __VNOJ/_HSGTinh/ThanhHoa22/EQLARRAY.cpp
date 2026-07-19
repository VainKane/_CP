#include <bits/stdc++.h>

using namespace std;

#define name "EQLARRAY"

int const N = 1e5 + 5;

int q;
int n, k;

int ma;
long long s;

int b[N];

bool Solve()
{
    if (s % k != 0) return false;
    if (ma > s / k) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> q;
    while (q--)
    {
        cin >> n >> k;

        ma = 0;
        s = 0;

        for (int i = 1; i <= n; i++) 
        {
            cin >> b[i];
            ma = max(ma, b[i]);
            s += b[i];
        }

        cout <<  (Solve() ? "YES\n" : "NO\n");
    }

    return 0;
}