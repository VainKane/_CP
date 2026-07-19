#include <bits/stdc++.h>

using namespace std;

bool Check(string s)
{
    stack<char> st;

    for (char bracket : s)
    {
        if (bracket != '(' && bracket != '[' && bracket != '{' && bracket != ')' && bracket != ']' && bracket != '}')
        {
            return false;
        }
        if (bracket == ')')
        {
            if (st.empty()) return false;
            if (st.top() == '(') st.pop();
            else return false;
        }
        else if (bracket == ']')
        {
            if (st.empty()) return false;
            if (st.top() == '[') st.pop();
            else return false;
        }
        else if (bracket == '}')
        {
            if (st.empty()) return false;
            if (st.top() == '{') st.pop();
            else return false;
        }
        else st.push(bracket);
    }

    return (st.empty());
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
