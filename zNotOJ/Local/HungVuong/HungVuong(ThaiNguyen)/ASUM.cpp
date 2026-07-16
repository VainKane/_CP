#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()
#define name "ASUM"

int const N = 1e5 + 5;

int n;
int a[N];

long long s, res = 0;
long long p[N];
vector<long long> b;

int bit[3 * N];

void Update(int idx, int val)
{
    while (idx <= b.size())
    {
        bit[idx] += val;
        idx += idx & -idx;
    }
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

int GetVal(long long x)
{
    return lower_bound(all(b), x) - b.begin() + 1;
}

void Init()
{
    FOR(i, 1, n)
    {
        p[i] = p[i - 1] + a[i];
        
        b.push_back(p[i]);
        b.push_back(p[i] - s);
        b.push_back(p[i] + s);
    }

    b.push_back(0);

    sort(all(b));
    b.erase(unique(all(b)), b.end());

    Update(GetVal(0), 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n >> s;
    FOR(i, 1, n) cin >> a[i];

    Init();

    FOR(i, 1, n)
    {
        res += Get(GetVal(p[i] - s) - 1);
        res += Get(b.size()) - Get(GetVal(p[i] + s));

        Update(GetVal(p[i]), 1);
    }

    cout << res;

    return 0; 
}