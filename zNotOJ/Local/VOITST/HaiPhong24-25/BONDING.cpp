#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define name "BONDING"

template <class t> bool maxi(t &x, t const &y)
{
    return x < y ? x = y, 1 : 0;
}

int const N = 402;

int m, n;
bool a[N][N];

int h[N], r[N];

int Solve()
{
    int res = 0;

    memset(h, 0, sizeof h);
    h[n + 1] = -1;

    FOR(i, 1, m)
    {
        stack<int> st;
        FOR(j, 1, n) h[j] = a[i][j] ? h[j] + 1 : 0;
        FOR(j, 1, n + 1) 
        {
            while (!st.empty() && h[j] < h[st.top()])
            {
                r[st.top()] = j;
                st.pop();
            }
            st.push(j);
        }
        
        FOR(j, 1, n) maxi(res, min(h[j], r[j] - j));
    }

    return res * res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    memset(a, true, sizeof a);
    
    cin >> m >> n;
    int q; cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;

        a[u][v] = false;
        cout << Solve() << '\n';
    }

    return 0;
}