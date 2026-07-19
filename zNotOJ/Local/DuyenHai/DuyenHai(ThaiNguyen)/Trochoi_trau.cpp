#include <bits/stdc++.h>

using namespace std;

#define name "Trochoi"

typedef long long ll;

int n;

ll Cal(ll x)
{
    ll res = 0;

    for (int i = 1; 1ll * i * i <= x; i++)
    {
        if (x % i == 0)
        {
            res += i;
            if (1ll * i * i != x) res += x / i;
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;

        cout << Cal(x) << ' ';
    }

    return 0;
}