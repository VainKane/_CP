#include <bits/stdc++.h>

using namespace std;

int n;
int a[(int)1e6 + 10];

stack<int> st;
int l[(int)1e6 + 10];
int r[(int)1e6 + 10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && a[i] > a[st.top()])
        {
            r[st.top()] = i + 1;
            st.pop();
        }
        st.push(i);
    }

    st = stack<int>();

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && a[i] > a[st.top()])
        {
            l[st.top()] = i + 1;
            st.pop();
        }
        st.push(i);
    }

    for (int i = 0; i < n; i++) cout << l[i] << ' ' << r[i] << '\n';

    return 0;
}