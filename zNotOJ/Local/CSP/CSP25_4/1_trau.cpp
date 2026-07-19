#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

string s;
int n;

int match[128];
int res = 0;

void Update(int l)
{
    stack<char> st;
    FOR(r, l, n)
    {
        if (!st.empty() && s[r] == match[st.top()]) st.pop();
        else st.push(s[r]);

        if (st.empty()) res = max(res, r - l + 1);
    }
}

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

    FOR(i, 1, n) Update(i);
    cout << res;

    return 0;
}