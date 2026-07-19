#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define name "SAPXEP"

int const N = 1e5 + 5;

int n, k;
int a[N];

bool used[N];

int ma = 0, ed = 0;

struct BIT
{
    vector<int> bit;
    int n;
    
    BIT(int _n)
    {
        n = _n;
        bit.resize(n + 5);
    }

    void Update(int idx, int val)
    {
        while (idx <= n)
        {
            bit[idx] = max(bit[idx], val);
            idx += idx & -idx;
        }
    }

    int GetMax(int idx)
    {
        int res = 0;

        while (idx)
        {
            res = max(res, bit[idx]);
            idx ^= idx & -idx;
        }

        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];

    BIT bit(n);
    FOR(i, 1, n)
    {
        int val = bit.GetMax(a[i] - 1);
        val++;

        if (val > ma)
        {
            ma = val;
            ed = i;
        }
        else if (val == ma && a[i] > a[ed]) ed = i;

        bit.Update(a[i], val);
    }

    // cout << ma << ' ' << ed << '\n';

    used[ed] = true;
    FORD(i, ed - 1, 1) if (a[i] < a[ed]) 
    {
        used[i] = true;
        ed = i;

        // cout << i << ' ';
    }

    vector<int> res;
    FOR(i, 1, n) if (!used[i]) 
    {
        res.push_back(a[i]);
        // cout << i << ' ';
        
    }
    sort(all(res));

    cout << res.size() << '\n';
    for (auto x : res) cout << x << ' ';

    return 0;
}