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
#define name ""

using ll = long long;
using ii = pair<int, int>;

template <class T> bool maxi(T &x, T const &y) { return x < y ? x = y, 1 : 0; }
template <class T> bool mini(T &x, T const &y) { return x > y ? x = y, 1 : 0; }

int const N = 1e5 + 5;

int n, h, w;

int l[N], r[N];
int d[2 * N];

void Compress()
{
    vector<int> vals;
    FOR(i, 1, n) if (l[i])
    {
        vals.push_back(l[i]);
        vals.push_back(r[i] + 1);
    }

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    FOR(i, 1, n) if (l[i])
    {
        l[i] = lower_bound(all(vals), l[i]) - vals.begin() + 1;
        r[i] = lower_bound(all(vals), r[i] + 1) - vals.begin() + 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> h >> w;
    FOR(i, 1, n)
    {
        int t, s;
        cin >> t >> s;

        l[i] = max(1, t - s + max(s + w - h, 1));
        r[i] = s <= w ? t : t - s + w;

        if (l[i] > r[i]) l[i] = r[i] = 0;
    }

    Compress();
    FOR(i, 1, n) if (l[i]) d[l[i]]++, d[r[i]]--;

    int pre = 0, res = 0;
    FOR(i, 1, 2 * n) pre += d[i], maxi(res, pre);
    cout << res;

    return 0;
}