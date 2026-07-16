#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define sz(v) ((int)v.size())
#define name "bolivia"

int const N = 3e5 + 5;

int n, q;
int h[N];
int cnt[3009];

long long Solve()
{
    memset(cnt, 0, sizeof cnt);

    FOR(i, 1, n / 2)
    {
        int a = h[i];
        int b = h[n - i + 1];

        if (a > b) swap(a, b);

        cnt[a + 1]++;
        cnt[b + 1]--;
    }

    FOR(i, 1, h[n / 2 + 1]) cnt[i] += cnt[i - 1];

    vector<int> st, ed;

    FOR(i, 1, h[n / 2 + 1]) if (!cnt[i])
    {
        if (i == 1 || cnt[i - 1] > 0) st.push_back(i);
        if (i == h[n / 2 + 1] || cnt[i + 1] > 0) ed.push_back(i);
    }

    long long res = 0;
    REP(i, sz(st))
    {
        int k = ed[i] - st[i] + 1;
        res += 1ll * k * (k + 1) / 2;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    cin >> n >> q;
    FOR(i, 1, n) cin >> h[i];

    cout << Solve();
    
    while (q--)
    {
        int tj, hj;
        cin >> tj >> hj;

        h[tj] = hj;
        cout << '\n' << Solve();
    }

    return 0;
}