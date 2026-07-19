#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 2e5 + 5;

int n;
int a[N];
int r[N];

void Init()
{
    stack<int> st;

    a[n + 1] = 0;
    FOR(i, 1, n + 1)
    {
        while (!st.empty() && a[i] <= a[st.top()])
        {
            r[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n;
        FOR(i, 1, n) cin >> a[i];

        Init();
        
        long long res = 0; 
        FOR(i, 1, n) res += a[i] != a[r[i]];
        cout << res << '\n';
    }

    return 0;
}