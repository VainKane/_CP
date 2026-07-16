#include <bits/stdc++.h>

using namespace std;

bool Check(string s)
{
    stack<char> st;

    for (char chr : s)
    {
        if (chr == '(' || chr == '[' || chr == '{')
        {
            st.push(chr);
        }
        else if (chr == ')' && !st.empty())
        {
            if (st.top() == '(') st.pop();
        }
        else if (chr == ']' && !st.empty())
        {
            if (st.top() == '[') st.pop();
        }
        else if (chr == '}' && !st.empty())
        {
            if (st.top() == '{') st.pop();
        }
        else return false;
    }

    return st.empty();
}

string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (cin >> s)
    {
        if (Check(s)) cout << "Y\n";
        else cout << "N\n";
    }

    return 0;
}