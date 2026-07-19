#include <bits/stdc++.h>

using namespace std;

stack<int> st;

int n;

int a[(int)1e6 + 10];
int b[(int)1e6 + 10];
int c[(int)1e6 + 10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        if (st.empty())
        {
            st.push(i);
        }
        else
        {
            while (!st.empty() && a[i] > a[st.top()])
            {
                b[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }
    }

    while (!st.empty())
    {
        c[st.top()] = 0;
        st.pop();
    }

    for (int i = n; i >= 1; i--)
    {
        if (st.empty())
        {
            st.push(i);
        }
        else
        {
            while (!st.empty() && a[i] > a[st.top()])
            {
                c[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }
    }

    while (!st.empty())
    {
        c[st.top()] = 0;
        st.pop();
    }

    for (int i = 1; i <= n; i++)
    {
        cout << c[i] << ' ' << b[i] << '\n';
    }

    return 0;
}
