#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define all(v) v.begin(), v.end()

int const N = 1e5 + 5;

struct Query
{
    int r, i;

    bool operator < (const Query other) const
    {
        return r < other.r;
    }
};

int n, q;
int a[N];
vector<Query> qr[N];

int lb[N];

int res[N];
int bit[N];

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
        idx -= idx & -idx;
    }

    return res;
}

int Get(int l, int r)
{
    return Get(r) - Get(l - 1);
}

void Init()
{
    stack<int> st;
    a[0] = -1;

    FORD(i, n, 0)
    {
        while (!st.empty() && a[i] <= a[st.top()])
        {
            lb[st.top()] = i;
            st.pop();
        }
        
        st.push(i);
        sort(all(qr[i]));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];

    Init();

    FOR(i, 1, q)
    {
        int l, r;
        cin >> l >> r;
        // qr[l].push_back({r, i});

        int res = 0;
        FOR(j, l, r) res += (lb[j] < l || a[lb[j]] < a[j]);
        cout << res << '\n';
    }


    return 0;
}