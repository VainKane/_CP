#include <bits/stdc++.h>

using namespace std;

bool Check(string str)
{
    stack<char> st;

    for (char key : str)
    {
        if (key != '(' && key != ')')
        {
            return false;
        }
        
        if (key == '(')
        {
            st.push(key);
        }
        else if (!st.empty())
        {
            st.pop();
        }
        else
        {
            return false;
        }
    }

    if (st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

string str;

int main()
{
    getline(cin, str);

    if (Check(str))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}