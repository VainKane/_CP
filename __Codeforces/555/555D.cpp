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

int const N = 2e5 + 5;

int n, m;

int x[N], id[N];
int pos[N];
bool dir;

bool cmp(int i, int j)
{
    return x[i] < x[j];
}

int GetRight(int len)
{
    x[0] = len;
    return id[upper_bound(id + 1, id + n + 1, 0, cmp) - id - 1];
}

int GetLeft(int len)
{
    x[0] = len;
    return id[lower_bound(id + 1, id + n + 1, 0, cmp) - id];
}

void SubCycle(int idx, int &len)
{
    int j = dir ? GetRight(x[idx] + len) : GetLeft(x[idx] - len);
    long long d = 2LL * abs(x[idx] - x[j]);

    idx = pos[idx];
    
    int d1 = abs(x[id[idx]] - (dir ? x[id[idx - 1]] : x[id[idx + 1]]));
    if (len - d >= d1) return;
    if (!d) return;

    len -= len / d * d;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, n) cin >> x[i], id[i] = i;

    sort(id + 1, id + n + 1, cmp);
    FOR(i, 1, n) pos[id[i]] = i;

    while (m--)
    {
        int idx, len;
        cin >> idx >> len;

        dir = 1;
        int cnt = 0;

        long long d = 2LL * (x[id[n]] - x[id[1]]);
        if (d) len -= len / d * d;
    
        while (true)
        {
            SubCycle(idx, len);
            int j = idx;

            if (dir) j = GetRight(x[idx] + len);
            else j = GetLeft(x[idx] - len);

            if (idx == j && ++cnt == 2)
            {
                cout << idx << '\n';
                break;
            }

            len -= abs(x[idx] - x[j]);
            idx = j;
            dir ^= 1;
        }
    }

    return 0;
}