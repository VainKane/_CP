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

int const N = 1e5 + 5;

int n, q;
int s[N], ss[N];
long long pre[N];

bool mark[N];

int res[N];

bool cmp(int i, int j)
{
    return s[i] < s[j];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> s[i], ss[i] = s[i];

    sort(ss + 1, ss + n + 1);
    FOR(i, 1, n) pre[i] = pre[i - 1] + ss[i];

    FOR(haha, 1, q)
    {
        int a, b, k;
        cin >> a >> b >> k;

        if (k == 0 && haha != 1)
        {
            cout << upper_bound(pre + 1, pre + n + 1, a + b) - pre - 2 << ' ';
            continue;
        }

        memset(mark, false, sizeof mark);
        memset(res, 0, sizeof res);

        while (k--)
        {
            int id; cin >> id;
            mark[id] = true;
        }

        vector<int> id;
        FOR(i, 1, n) if (!mark[i]) id.push_back(i);

        sort(all(id), cmp);

        int cnt = 0;
        for (auto &i : id)
        {
            if (a >= s[i]) res[i] = 1, a -= s[i];
            else if (b >= s[i]) res[i] = 2, b -= s[i];
            cnt += res[i] != 0;
        }

        if (haha == 1)
        {
            cout << cnt << '\n';
            FOR(i, 1, n) cout << res[i];
            cout << '\n';
        }
        else cout << cnt << ' ';
    }

    return 0;
}