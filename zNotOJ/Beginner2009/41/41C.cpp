#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define F first
#define S second

using namespace std;

struct Query
{
    int i, j, k;
};

int const N = 5e4 + 5;
int const M = 2e5 + 5;

int n, m;

int a[N];
int bit[N];
vector<int> b;

pair<int, int> bd[M];
Query q[M];
int res[M];

vector<int> group[N];
vector<int> pos[N];

void Update(int idx, int val)
{
    while (idx <= n)
    {
        bit[idx] += val;
        idx += idx & -idx;
    }
}

int Get(int idx)
{
    int res = 0;
    
    while (idx)
    {
        res += bit[idx];
        idx -= idx & -idx;
    }

    return res;
}

void Reset()
{
    for (int i = 1; i <= n; i++) group[i].clear();
    memset(bit, 0, sizeof bit);
}

void Init()
{
    for (int i = 1; i <= n; i++) b.push_back(a[i]);
    sort(all(b));
    b.erase(unique(all(b)), b.end());
    
    for (int i = 1; i <= n; i++) 
    {
        a[i] = lower_bound(all(b), a[i]) - b.begin() + 1;
        pos[a[i]].push_back(i);
    }

    for (int i = 1; i <= m; i++) bd[i] = {1, n};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int huhu = 1; huhu <= m; huhu++)
    {
        int i, j, k;
        cin >> i >> j >> k;
        q[huhu] = {i, j, k};
    }

    Init();

    for (int haha = 1; haha <= 16; haha++) 
    {
        Reset();
        
        for (int i = 1; i <= m; i++) 
        {
            if (bd[i].F > bd[i].S) continue;

            int mid = (bd[i].F + bd[i].S) / 2;
            group[mid].push_back(i);
        }

        for (int mid = 1; mid <= n; mid++)
        {
            for (auto i : group[mid])
            {
                int cnt = Get(q[i].j) - Get(q[i].i - 1);
                
                if (cnt <= q[i].k - 1)
                {
                    res[i] = b[mid - 1];
                    bd[i].F = mid + 1;
                }
                else bd[i].S = mid - 1;
            }

            for (auto i : pos[mid]) Update(i, 1);
        }
    }

    for (int i = 1; i <= m; i++) cout << res[i] << '\n';

    return 0;
}