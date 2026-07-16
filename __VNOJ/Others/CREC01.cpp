#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)

int const N = 1009;

int m, n;

char a[N][N];
int h[N], r[N], f[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];

    h[0] = h[n + 1] = -1;
    long long res = 0;

    FOR(i, 1, m)
    {
        FOR(j, 1, n) h[j] = a[i][j] == '1' ? h[j] + 1 : 0;
        
        stack<int> st;
        FOR(j, 1, n + 1)
        {
            while (!st.empty() && h[j] < h[st.top()])
            {
                r[st.top()] = j;
                st.pop();
            }
            st.push(j);
        }

        FORD(j, n, 1)
        {
            f[j] = 1ll * h[j] * (r[j] - j) + f[r[j]];
            res += f[j];
        }
    }

    cout << res;

    return 0;
}