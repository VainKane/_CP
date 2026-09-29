#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1LL << (i))
#define all(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define F first
#define S second

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

template <class t> bool mini(t &x, t const &y)
{
    return x > y ? x = y, 1 : 0;
}

int const N = 2009;

int n, m, k;

int a[N][N];
int maxH[N][N];
int pre[N][N];

vector<int> h;
int avail[N];

bool Check(int i, int j)
{
    vector<int> v;
    FOR(id, j, j + k - 1) v.push_back(maxH[i - 1][id]);
    sort(all(v));
    
    REP(id, k) if (h[id] <= v[id]) return false;
    return true;
}

bool Valid(int i, int j)
{
    return pre[i][j + k - 1] - pre[i][j - 1] == 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n >> k;

    FOR(i, 1, k)
    {
        int x; cin >> x;
        h.push_back(x);
    }
    
    memset(maxH, -0x3f, sizeof maxH);

    FOR(i, 1, m) FOR(j, 1, n) 
    {
        cin >> a[i][j];
        pre[i][j] = pre[i][j - 1] + a[i][j];
        maxH[i][j] = max(maxH[i - 1][j], a[i][j]);
    }

    sort(all(h));
    int res = 0;

    FOR(j, 1, n)
    {
        int l = 0;
        int r = m;
        avail[j] = l;

        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (Check(mid, j))
            {
                avail[j] = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
    }

    FORD(i, m, 1) FOR(j, 1, n - k + 1)
        res += Valid(i, j) && avail[j] >= i;
    
    cout << res;

    return 0;
}