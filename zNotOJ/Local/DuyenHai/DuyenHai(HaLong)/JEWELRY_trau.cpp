#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define F first
#define S second
#define name "JEWELRY"

int const N = 1e5 + 5;
int const LOG = 7;
int const MAXLOG = (1 << LOG) + 5;

int n;
int m; // m = x
int y;

int a[N];
int s[N][10];

long long res = 0;

// sub 1
int xy[N];
int xn[N];
bool used[N];

vector<int> c;

// sub2
pii b[N];

// sub3
long long dp[N][MAXLOG];

void Try(int pos, int k, int n, int x[], bool cal) // codeban.com :>
{
    if (pos > k)
    {
        // for (int i = 1; i <= k; i++)
        // {
        //     cout << x[i] << ' ';
        // }
        // cout << '\n';

        if (!cal) 
        {
            Try(1, y, m + y, xy, true);
        }
        else
        {
            long long sum = 0;
            memset(used, 0, sizeof used);

            for (int i = 1; i <= y; i++)
            {
                sum += a[xn[xy[i]]];
                used[xn[xy[i]]] = true;
            }

            vector<int> bb;
            bb.push_back(0);

            for (int j = 1; j <= m + y; j++)
            {
                if (!used[xn[j]]) bb.push_back(xn[j]);
            }

            do
            {
                long long sum1 = 0;
                for (int i = 1; i <= m; i++)
                {
                    sum1 += s[bb[i]][c[i]];
                }
                res = max(res, sum + sum1);
            } while (next_permutation(all(c)));
        }

        return;
    }

    for (int i = x[pos - 1] + 1; i <= n - k + pos; i++)
    {
        x[pos] = i;
        Try(pos + 1, k, n, x, cal);
    }
}

void Sub1()
{
    c.push_back(0);
    for (int i = 1; i <= m; i++) c.push_back(i);
    Try(1, m + y, n, xn, false);

    cout << res;

    // cout << "-------------\n";
}

void Sub2()
{
    for (int i = 1; i <= n; i++)
    {
        b[i] = {a[i], i};
    }

    sort(b + 1, b + n + 1, greater<pii> ());

    long long s1 = 0;
    long long s2 = 0;

    for (int i = 1; i <= y; i++) s1 += b[i].F;
    s2 = s1 + b[y + 1].F;

    for (int i = 1; i <= y; i++)
    {
        res = max(res, s2 - b[i].F + s[b[i].S][1]);
    }
    for (int i = y + 1; i <= n; i++)
    {
        res = max(res, s1 + s[b[i].S][1]);
    }

    cout << res;
}

bool CheckSub3()
{
    for (int i = 2; i <= n; i++)
    {
        if (a[i] != a[i - 1]) return false;
    }

    return true;
}

int bit(int i, int mask)
{
    return (mask >> i) & 1;
}

int on(int i, int mask)
{
    return mask | (1 << i);
}

void Sub3()
{
    for (int i = 0; i < n; i++)
    {
        for (int mask = 0; mask < (1 << m); mask++)
        {
            dp[i + 1][mask] = max(dp[i + 1][mask], dp[i][mask]); // khong chon da i + 1
            for (int j = 0; j < m; j++)
            {
                if (bit(j, mask)) continue;
                dp[i + 1][on(j, mask)] = max(dp[i + 1][on(j, mask)], dp[i][mask] + s[i + 1][j + 1]); // chon da i + 1, gan vao nhan j 
            }
        }
    }

    cout << dp[n][(1 << m) - 1] + 1ll * y * a[1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> m >> y;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> s[i][j];
        }
    }

    if (CheckSub3()) Sub3();
    else if (m == 1) Sub2();
    else Sub1();

    return 0;
}