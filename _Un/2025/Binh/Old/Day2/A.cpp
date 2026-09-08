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

int m, n, A, B;
int a[N][N];

long long col[N], pre[N];
int res = 2e9 + 1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("A.inp", "r", stdin);

    cin >> m >> n >> A >> B;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];
   
    if (A > B) swap(A, B);
    res = abs(a[1][1] - A) + abs(a[1][1] - B);

    FOR(l, 1, m) 
    {
        memset(col, 0, sizeof col);
        FOR(r, l, m)
        {
            int i = 1;
            FOR(j, 1, n) 
            {
                col[j] += a[r][j];
                pre[j] = pre[j - 1] + col[j];

                while (pre[j] - pre[i - 1] > B && i < j) 
                {
                    long long s = pre[j] - pre[i - 1];
                    mini(res, s + s - A - B);
                    i++;
                }
                
                long long s = pre[j] - pre[i - 1];
                if (s >= A && s <= B)
                {
                    cout << B - A;
                    return 0;
                }
                mini(res, abs(s - A) + abs(s - B));
            }
        }
    }   

    cout << res;

    return 0;
}