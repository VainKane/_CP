#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

struct FenwickTree
{
    vector<int> bit;
    int n;

    FenwickTree(int _n = 0)
    {
        n = _n;
        bit.resize(n + 3);
    }

    void Update(int idx, int val)
    {
        while (idx <= n)
        {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    void Update(int l, int r, int val)
    {
        if (l > r) return;
        Update(l, val);
        Update(r + 1, -val);
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
};

int const N = 25e4 + 5;

int n;
int w[N], h[N];

int r[N];

FenwickTree bit;

void Init()
{
    stack<int> st;
    FOR(i, 1, n + 1)
    {
        while (!st.empty() && h[i] < h[st.top()])
        {
            r[st.top()] = i - 1;
            st.pop();
        }
        st.push(i);
    }

    bit = FenwickTree(n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> w[i] >> h[i];

    Init();
    
    int res = 0;
    FOR(i, 1, n) if (bit.Get(i) != h[i])
    {
        bit.Update(i, r[i], h[i]);
        res++;
    }

    cout << res;

    return 0;
}