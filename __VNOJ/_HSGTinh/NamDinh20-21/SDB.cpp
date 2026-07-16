#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define name "SDB"

int const N = 1e6 + 5;

int n;
int a[N];
vector<int> b;

int cnt[N];

vector<int> res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b.push_back(a[i]);
    }

    sort(all(b));
    b.erase(unique(all(b)), b.end());

    for (int i = 1; i <= n; i++) 
    {
        a[i] = lower_bound(all(b), a[i]) - b.begin() + 1;
        cnt[a[i]]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (cnt[a[i]] == 1) res.push_back(b[a[i] - 1]);
    }

    cout << res.size() << '\n';
    for (auto x : res) cout << x << '\n';

    return 0;
}