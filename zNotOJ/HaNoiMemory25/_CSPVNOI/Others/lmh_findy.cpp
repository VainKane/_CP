#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int GetY(int x, int k)
{
    int n = (x - 1) / k;
    return k * n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        int x; cin >> x;

        long long res = 0;
        
        FOR(i, 1, sqrt(x)) if (x % i == 0)
        {
            maxi(res, 1ll * i * GetY(x, i));
            maxi(res, 1ll * (x / i) * GetY(x, x / i));
        }

        cout << res << '\n';
    }

    return 0;
}