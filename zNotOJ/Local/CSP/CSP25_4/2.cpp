#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()
#define F first
#define S second

int const N = 2e5 + 5;
int const LOG = 18;

int n, q;
int a[N];

vector<int> values;
vector<int> group[N];

pair<int, int> qr[N], bd[N];

vector<int> cnt[N];
int res[N];

void Init()
{
    FOR(i, 1, n) values.push_back(a[i]);

    sort(all(values));
    values.erase(unique(all(values)), values.end());
    FOR(i, 1, n) a[i] = lower_bound(all(values), a[i]) - values.begin() + 1;

    FOR(i, 1, q) bd[i] = {1, values.size()};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("2.inp", "r", stdin);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, q)
    {
        int l, r;
        cin >> l >> r;
        qr[i] = {l, r};
    }

    Init();

    FOR(haha, 1, LOG)
    {
        FOR(mid, 1, values.size()) group[mid].clear();
        FOR(i, 1, q)
        {
            if (bd[i].F > bd[i].S) continue;
            group[(bd[i].F + bd[i].S) / 2].push_back(i);            
        }

        FOR(mid, 1, values.size()) 
        {
            if (!group[mid].empty() && cnt[mid].empty()) 
            {
                cnt[mid].resize(n + 1);
                FOR(i, 1, n) cnt[mid][i] = cnt[mid][i - 1] + (a[i] <= mid ? 1 : -1);
            }

            for (auto &id : group[mid])
            {
                if (cnt[mid][qr[id].F - 1] + cnt[mid][n] - cnt[mid][qr[id].S] >= 0)
                {
                    res[id] = values[mid - 1];
                    bd[id].S = mid - 1;
                }
                else bd[id].F = mid + 1;
            }
        }
    }

    FOR(i, 1, q) cout << res[i] << '\n';

    return 0;
}