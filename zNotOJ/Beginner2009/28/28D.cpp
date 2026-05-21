#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define fi first
#define se second
#define name "28D"

int const N = 1e5 + 5;

int n;

int a[N];
int bit[N];
vector<int> b;

int trace[N];
int pos[N];

void Update(int idx, int val, int k)
{
    while (idx <= n)
    {
        if (bit[idx] < val)
        {
            bit[idx] = val;
            pos[idx] = k;
        }
        idx += idx & -idx;
    }
}

int GetMax(int idx, int &p)
{
    int res = 0;

    while (idx)
    {
        if (res < bit[idx])
        {
            res = bit[idx];
            p = pos[idx];
        }
        idx -= idx & -idx;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen(name".inp", "r", stdin);
    // freopen(name".out", "w", stdout);
    
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b.push_back(a[i]);
    }

    sort(all(b));
    b.erase(unique(all(b)), b.end());

    for (int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(all(b), a[i]) - b.begin() + 1;
    }

    int res = 0;
    int idx;

    for (int i = 1; i <= n; i++)
    {
        int p = 0;
        int val = GetMax(a[i] - 1, p) + 1;
        Update(a[i], val, i);
        
        trace[i] = p;

        if (val > res) 
        {
            idx = i;
            res = val;
        }
    }

    vector<int> mark;

    while (idx)
    {
        mark.push_back(b[a[idx] - 1]);
        idx = trace[idx];
    }

    reverse(all(mark));

    cout << mark.size() << '\n';
    for (auto val : mark) cout << val << ' ';

    return 0;
}