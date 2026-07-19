#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

template <class X, class Y>
    bool mini(X &x, Y const &y)
    {
        if (x > y)
        {
            x = y;
            return true;
        }
        return false;
    }

int const N = 509;

int m, n;
bool a[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n) 
    {
        char x; cin >> x;
        a[i][j] = (x == 'x');
    }

    int q; cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;

        int res = 1e9;
        FOR(i, 1, m) FOR (j, 1, n) if (a[i][j])
        {
            int u = i - x;
            int v = j - y;
            
            mini(res, u * u + v * v);
        }

        a[x][y] = true;
        cout << res << '\n';
    }

    return 0;
}