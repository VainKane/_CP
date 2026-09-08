#include <bits/stdc++.h>

using namespace std;

int n;
int a[(int)3e5 + 10];

stack<int> st;

int lMax[(int)3e5 + 10];
int lMin[(int)3e5 + 10];
int rMax[(int)3e5 + 10];
int rMin[(int)3e5 + 10];

long long res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("15C.inp", "r", stdin);
    // freopen("15C.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        while (!st.empty() && a[i] >= a[st.top()])
        {
            rMax[st.top()] = i - 1;
            st.pop();
        }
        st.push(i);
    }
    
    while (!st.empty())
    {
        rMax[st.top()] = n;
        st.pop();
    }

    for (int i = n; i >= 1; i--)
    {
        while (!st.empty() && a[i] > a[st.top()])
        {
            lMax[st.top()] = i + 1;
            st.pop();
        }
        st.push(i);
    }
    
    while (!st.empty())
    {
        lMax[st.top()] = 1;
        st.pop();
    }

    //

    for (int i = 1; i <= n; i++)
    {
        while (!st.empty() && a[i] <= a[st.top()])
        {
            rMin[st.top()] = i - 1;
            st.pop();
        }
        st.push(i);
    }
    
    while (!st.empty())
    {
        rMin[st.top()] = n;
        st.pop();
    }

    for (int i = n; i >= 1; i--)
    {
        while (!st.empty() && a[i] < a[st.top()])
        {
            lMin[st.top()] = i + 1;
            st.pop();
        }
        st.push(i);
    }
    
    while (!st.empty())
    {
        lMin[st.top()] = 1;
        st.pop();
    }

    for (int i = 1; i <= n; i++)
    {
        long long c = (1ll * (i - lMax[i] + 1) * (rMax[i] - i + 1)) - 1;
        long long d = (1ll * (i - lMin[i] + 1) * (rMin[i] - i + 1)) - 1;

        res += 1ll * a[i] * (c - d);
    }

    cout << res;

    return 0;
}