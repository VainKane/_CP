#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())

template <class t> bool maxi (t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

struct FenwickTree
{
    vector<int> bit;
    int n;

    FenwickTree(int _n = 0)
    {
        n = _n;
        bit.assign(n + 5, 0);
    }

    void Update(int idx, int val)
    {
        while (idx)
        {
            mini(bit[idx], val);
            idx ^= idx & -idx;
        }
    }

    int Get(int idx, int val)
    {
        int res = 0;

        while (idx <= n)
        {
            mini(res, bit[idx]);
            idx += idx & -idx;
        }

        return res;
    }
};

int const N = 2e5 + 5;

int n;

int a[N];
long long pre[N];
FenwickTree bit;

long long s = 0;

vector<int> vals;

int GetId(long long const &x)
{
    return lower_bound(all(vals), x) - vals.begin() + 1;
}

void Compress()
{
    FOR(i, 1, 2 * n) vals.push_back(pre[i]);

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, 2 * n) pre[i] = GetId(pre[i]);
}

void Init()
{
    Compress();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) 
    {
        cin >> a[i];
        a[n + i] = a[i];
    }

    FOR(i, 1, 2 * n) pre[i] = pre[i - 1] + a[i];

    int pos = 1;

    int q; cin >> q;
    while (q--)
    {
        int x; cin >> x;

        int res = x / s * n;
        x -= x / s * s;



        cout << res << '\n';
    }

    return 0;
}