#include <bits/stdc++.h>

using namespace std;

int Cal(string a, string b)
{
    int res = 0;

    for (int i = 0; i < min(a.length(), b.length()); i++)
    {
        if (a[i] != b[i]) return res;
        res++;
    }

    return res;
}

int n;
string str[1000009];
int b[1000009];

int l[1000009];
int r[1000009];

long long res = 0;

stack<int> st;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) cin >> str[i]; 
    sort(str, str + n);
    for (int i = 1; i < n; i++) b[i - 1] = Cal(str[i], str[i - 1]);

    for (int i = 0; i < n - 1; i++)
    {
        while (!st.empty() && b[st.top()] > b[i])
        {
            r[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        r[st.top()] = n - 1;
        st.pop();
    }

    for (int i = n - 2; i >= 0; i--)
    {
        while (!st.empty() && b[st.top()] > b[i])
        {
            l[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    while (!st.empty())
    {
        l[st.top()] = -1;
        st.pop();
    }

    // for (int i = 0; i < n - 1; i++) cout << b[i] << ' ';
    // cout << '\n';    
    // for (int i = 0; i < n - 1; i++) cout << l[i] << ' ';
    
    for (int i = 0; i < n - 1; i++)
    {
        res = max(res, 1ll * b[i] * ((r[i] - 1) - (l[i] + 1) + 2));
    }

    cout << res;

    return 0;
}