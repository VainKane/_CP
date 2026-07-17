#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 1e5 + 5;

string s;
int n;

int match[128];
int start[N];
int res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;
    
    n = s.size();
    s = " " + s;

    match['('] = ')';
    match['['] = ']';
    match['{'] = '}';
    match['<'] = '>';

    stack<int> st;
    FOR(i, 1, n) 
    {
        if (!st.empty() && match[s[st.top()]] == s[i]) 
        {
            start[i] = st.top();
            st.pop();
        }
        else st.push(i);
    }

    // FOR(i, 1, n) cout << start[i] << ' ' << i << '\n';

    FOR(i, 1, n) if (start[i])
    {
        int j = start[i];
        if (start[j - 1]) start[i] = start[j - 1];

        res = max(res, i - start[i] + 1);
    }

    cout << res;

    return 0;
}