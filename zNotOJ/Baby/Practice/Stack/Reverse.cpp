#include <bits/stdc++.h>

using namespace std;

string str;
stack<char> st;

int main()
{
    getline(cin, str);

    for (char key : str)
    {
        st.push(key);
    }

    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
}