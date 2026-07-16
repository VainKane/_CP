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
            idx ^= idx & -idx;
        }

        return res;
    }

    int Get(int l, int r)
    {
        if (l > r) return 0;
        return Get(r) - Get(l - 1);
    }
};

int const N = 3009;

int m, n;
char a[N][N];

int l[N][N], r[N][N];
bool visited[N][N];

vector<int> v[N];
FenwickTree bit;

void Init()
{
    FOR(i, 1, m)
    {
        int last = 0;
        FOR(j, 1, n)
        {
            if (a[i][j] == '.') last = j;
            else l[i][j] = j - last - 1;
        }

        last = n + 1;
        FORD(j, n, 1)
        {
            if (a[i][j] == '.') last = j;
            else r[i][j] = last - j - 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    Init();

    long long res = 0;
    FOR(i, 1, m) FOR(j, 1, n) if (a[i][j] == 'z' && !visited[i][j])
    {
        int cnt = 0;
        for (int x = i, y = j; x <= m && y >= 1 && a[x][y] == 'z'; x++, y--) 
        {
            cnt++;
            v[x].clear();
        }

        v[m + 1].clear();
        bit = FenwickTree(cnt);

        for (int x = i, y = j; x <= m && y >= 1 && a[x][y] == 'z'; x++, y--)
        {
            res += bit.Get(max(1, x - r[x][y] - i + 1), x - 1 - i + 1) + 1;

            bit.Update(x - i + 1, 1);
            v[min(m + 1, x + l[x][y])].push_back(x);

            for (auto &idx : v[x]) bit.Update(idx - i + 1, -1);
            visited[x][y] = true;
        }
    }

    cout << res;

    return 0;
}