#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 5009;

int n, k;
int l, r, SG;

int a[N], d[N];
long long f[2][N], g[2][N];

int cur, pre;

void Init()
{
    memset(f, -1, sizeof f);
    
    cur = 1, pre = 0;
    
    FOR(j, 1, k) d[j] = 2 * j * (k - j);
    FOR(i, 1, n) if (a[i] >= l && a[i] <= r) 
    {
        f[cur][i] = 0;
        g[cur][i] = -d[1] * a[i];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    cin >> l >> r;
    cin >> SG;

    FOR(i, 1, n) cin >> a[i];

    Init();

    FOR(j, 2, k) 
    {
        deque<int> q;
        int idx = 0;

        swap(cur, pre);
        memset(f[cur], -1, sizeof f[cur]);

        FOR(i, j, n)
        {
            while (!q.empty() && a[i] - a[q.front()] > r) q.pop_front();
            while (idx - 1 < i && a[i] - a[idx + 1] >= l)
            {
                idx++;
                if (f[pre][idx] == -1) continue;

                if (idx == 1 && a[idx] >= l && a[idx] <= r) q.push_back(idx);
                else
                {
                    while (!q.empty() && g[pre][q.back()] <= g[pre][idx]) q.pop_back();
                    q.push_back(idx);
                }
            }

            if (!q.empty()) 
            {
                f[cur][i] = g[pre][q.front()] + 1ll * d[j - 1] * a[i];
                g[cur][i] = f[cur][i] - 1ll * d[j] * a[i];
            }
        }
    }

    long long res = 0;

    FOR(i, k, n)
    {
        int tmp = SG - a[i];
        if (tmp >= l && tmp <= r) res = max(res, f[cur][i]);
    }
    cout << res;

    return 0;
}