#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

struct Event
{
    int l, r, c;
};

int const N = 1e5 + 5;

int n, m, k;
vector<int> sta[N];
int w[N];

Event a[N];
vector<int> group[N];

pair<int, int> bd[N];
int res[N];

long long bit[N];

void Update(int idx, int val)
{
    while (idx <= m)
    {
        bit[idx] += val;
        idx += idx & -idx;
    }
}

void Update(int l, int r, int val)
{
    Update(l, val);
    Update(r + 1, -val);
}

long long Get(int idx)
{
    long long res = 0;

    while (idx)
    {
        res += bit[idx];
        idx -= idx & -idx;
    }

    return res;
}

void Init()
{
    for (int i = 1; i <= n; i++) bd[i] = {1, k};
    memset(res, -1, sizeof res);
}

void Reset()
{
    for (int i = 1; i <= k; i++) group[i].clear();
    memset(bit, 0, sizeof bit);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int p; cin >> p;
        sta[p].push_back(i);
    }

    for (int i = 1; i <= n; i++) cin >> w[i];

    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        int l, r, c;
        cin >> l >> r >> c;
        a[i] = {l, r, c};
    }

    Init();

    for (int haha = 1; haha <= 17; haha++)
    {
        Reset();

        for (int i = 1; i <= n; i++)
        {
            if (bd[i].F > bd[i].S) continue;

            int mid = (bd[i].F + bd[i].S) / 2;
            group[mid].push_back(i);
        }

        for (int mid = 1; mid <= k; mid++)
        {
            int l = a[mid].l;
            int r = a[mid].r;
            int c = a[mid].c;

            if (l <= r) Update(l, r, c);
            else
            {
                Update(l, m, c);
                Update(1, r, c);
            }

            for (auto i : group[mid])
            {
                long long sum = 0;
                for (auto x : sta[i])
                {
                    if (sum >= w[i]) break;
                    sum += Get(x);
                }

                if (sum >= w[i])
                {
                    res[i] = mid;
                    bd[i].S = mid - 1;
                }
                else bd[i].F = mid + 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) cout << res[i] << '\n';

    return 0;
}