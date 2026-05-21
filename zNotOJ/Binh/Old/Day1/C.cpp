#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)

template <class X, class Y>
    bool maxi(X &x, Y const &y)
    {
        if (x < y)
        {
            x = y;
            return true;
        }
        return false;
    }

int const N = 1009;

int m, n;

int a[N][N];
bool b[N][N];

int h[N];
int l[N], r[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    FOR(i, 1, m - 1) FOR(j, 1, n - 1) b[i][j] = (a[i][j] + a[i + 1][j + 1] <= a[i][j + 1] + a[i + 1][j]);

    int res = 0;

    // FOR(i, 1, m - 1)
    // {
    //     FOR(j, 1, n - 1) cout << b[i][j];
    //     cout << '\n';
    // }

    FOR(i, 1, m - 1)
    {
        FOR(j, 1, n - 1) h[j] = b[i][j] ? h[j] + 1 : 0;

        stack<int> st;

        FOR(j, 1, n)
        {
            while (!st.empty() && (h[j] < h[st.top()] || !h[j]))
            {
                r[st.top()] = j;
                st.pop();
            }
            st.push(j);
        } 
        FORD(j, n - 1, 0)
        {
            while (!st.empty() && (h[j] < h[st.top()] || !h[j]))
            {
                l[st.top()] = j;
                st.pop();
            }
            st.push(j);
        } 

        FOR(j, 1, n - 1) if (h[j]) maxi(res, (h[j] + 1) * (r[j] - l[j]));
    }

    cout << res;

    return 0;
}