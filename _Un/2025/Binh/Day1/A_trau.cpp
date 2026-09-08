#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()

int const N = 3e5 + 5;

int n;

int x[N], y[N];
vector<int> xValues, yValues;
vector<int> posY[N], posX[N];

void Build(vector<int> &values, vector<int> pos[], int a[], int b[])
{
    FOR(i, 1, n) values.push_back(a[i]);
    sort(all(values));
    values.erase(unique(all(values)), values.end());

    FOR(i, 1, n) 
    {
        int val = lower_bound(all(values), a[i]) - values.begin() + 1;
        pos[val].push_back(b[i]);
    }

    FOR(i, 1, n) sort(all(pos[i]));
}

int GetId(vector<int> &values, int &val)
{
    int idx = lower_bound(all(values), val) - values.begin() + 1;
    if (values[idx - 1] != val) return 0;
    return idx;
}

int Cal(vector<int> &pos, int &l, int &r)
{
    if (l > r) return 0;
    return upper_bound(all(pos), r) - lower_bound(all(pos), l);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> x[i] >> y[i];

    Build(xValues, posY, x, y);
    Build(yValues, posX, y, x);

    int q; cin >> q;
    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int u1 = GetId(xValues, x1);
        int u2 = GetId(xValues, x2);
        int v1 = GetId(yValues, y1);
        int v2 = GetId(yValues, y2);

        x1++; x2--;
        int res = 0;
        
        res += Cal(posY[u1], y1, y2);
        if (u1 != u2) res += Cal(posY[u2], y1, y2);
        
        res += Cal(posX[v1], x1, x2);
        if (v1 != v2) res += Cal(posX[v2], x1, x2);

        cout << res << '\n';
    }

    return 0;
}