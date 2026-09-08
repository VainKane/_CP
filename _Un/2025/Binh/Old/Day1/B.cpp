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
int a[N][N], pre[N][N];

int h[N];
int l[N], r[N];

int res = 0;

int Get(int top, int bot, int left, int right)
{
    return pre[bot][right] - pre[bot][left - 1] - pre[top - 1][right] + pre[top - 1][left - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    memset(a, -1, sizeof a);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n) 
    {
        cin >> a[i][j];
        pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
        
    }

    FOR(i, 1, m)
    {
        FOR(j, 1, n) h[j] = a[i][j] != -1 ? h[j] + 1 : 0;

        stack<int> st;
        FOR(j, 1, n + 1)
        {
            while (!st.empty() && (a[i][j] == -1 || h[j] < h[st.top()]))
            {
                r[st.top()] = j - 1;
                st.pop();
            }
            st.push(j);
        }

        FORD(j, n, 0)
        {
            while (!st.empty() && (a[i][j] == -1 || h[j] < h[st.top()]))
            {
                l[st.top()] = j + 1;
                st.pop();
            }
            st.push(j);
        }

        FOR(j, 1, n) maxi(res, Get(i - h[j] + 1, i, l[j], r[j]));
    }

    cout << res;

    return 0;
}