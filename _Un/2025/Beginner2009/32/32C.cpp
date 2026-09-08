#include <bits/stdc++.h>

using namespace std;

int const N = 5e4 + 5;

int n;
int m;

pair<int, int> a[N];
vector<int> t[4 * N];

void Build(int v, int l, int r)
{
    if (l == r)
    {
        t[v].push_back(a[l].second);
        return;
    }

    int mid = l + (r - l) / 2;
    Build(2 * v, l, mid);
    Build(2 * v + 1, mid + 1, r);

    t[v].resize(t[2 * v].size() + t[2 * v + 1].size());
    merge(t[2 * v].begin(), t[2 * v].end(), t[2 * v + 1].begin(), t[2 * v + 1].end(), t[v].begin());
}

int Query(int v, int l, int r, int left, int right, int k)
{
    if (l == r) return a[l].first;

    int mid = l + (r - l) / 2;

    auto it1 = upper_bound(t[2 * v].begin(), t[2 * v].end(), right);
    auto it2 = lower_bound(t[2 * v].begin(), t[2 * v].end(), left);
    
    if (it1 - it2 >= k) return Query(2 * v, l, mid, left, right, k); 
    return Query(2 * v + 1, mid + 1, r, left, right, k - (it1 - it2));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
    {
        int x;
        cin >> x;

        a[i] = {x, i};
    }

    sort(a + 1, a + n + 1);
    Build(1, 1, n);

    while (m--)
    {
        int i, j, k;
        cin >> i >> j >> k;

        cout << Query(1, 1, n, i, j, k) << '\n';
    }

    return 0;
}