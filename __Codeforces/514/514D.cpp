#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define MK(i) (1 << (i))

int const N = 1e5 + 5;
int const M = 7;
int const LOG = 17;

int n, m, k;

int a[M][N];
int up[M][N][20];
int lg[N];

int tmp[M], res[M];

void Init()
{
    FOR(p, 1, m) FOR(i, 1, n) up[p][i][0] = a[p][i];
    FOR(p, 1, m) FOR(j, 1, LOG) FOR(i, 1, n - MK(j) + 1)
        up[p][i][j] = max(up[p][i][j - 1], up[p][i + MK(j - 1)][j - 1]);

    FOR(i, 2, n) lg[i] = lg[i >> 1] + 1;
}

int GetMax(int p, int l, int r)
{
    int k = lg[r - l + 1];
    return max(up[p][l][k], up[p][r - MK(k) + 1][k]);
}

bool Check(int &l)
{
    FOR(i, 1, n - l + 1) 
    {
        long long cost = 0;
        FOR(j, 1, m) 
        {
            tmp[j] = GetMax(j, i, i + l - 1);
            cost += tmp[j];
        }
        if (cost <= k) return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    FOR(i, 1, n) FOR(p, 1, m) cin >> a[p][i];

    Init();

    int l = 0;
    int r = n;

    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (Check(mid))
        {
            memcpy(res, tmp, sizeof res);
            l = mid + 1;
        }
        else r = mid - 1;
    }

    FOR(i, 1, m) cout << res[i] << ' ';

    return 0;
}