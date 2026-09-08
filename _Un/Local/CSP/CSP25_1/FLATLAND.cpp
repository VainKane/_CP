#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define all(v) v.begin(), v.end()
#define name "FLATLAND"

int const N = 1e3 + 5;

int m, n;
int a[N][N];

int h[N];
int l[N], r[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    int res = 0;

    FOR(i, 1, m) 
    {
        FOR(j, 1, n)
        {
            if (a[i][j] != a[i - 1][j]) h[j] = 1;
            else h[j]++;
        }

        stack<int> st;
        
        FOR(j, 1, n + 1)
        {
            while (!st.empty() && (h[j] < h[st.top()] || a[i][j] != a[i][st.top()]))
            {
                r[st.top()] = j;
                st.pop();
            }
            st.push(j);
        }

        FORD(j, n, 0)
        {
            while (!st.empty() && (h[j] < h[st.top()] || a[i][j] != a[i][st.top()]))
            {
                l[st.top()] = j;
                st.pop();
            }
            st.push(j);
        }
        
        FOR(j, 1, n) res = max(res, h[j] + r[j] - l[j] - 1);
    }

    cout << res + res;

    return 0;
}