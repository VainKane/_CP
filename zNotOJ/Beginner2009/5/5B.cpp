#include <bits/stdc++.h>

using namespace std;

string s;
int k;

stack<char> st;
string res = "";

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;
    cin >> k;

    for (char digit : s)
    {
        while (!st.empty() && st.top() > digit && k > 0)
        {
            st.pop();
            k--;
        }

        st.push(digit);
    }  
    
    while (!st.empty() && k > 0)
    {
        st.pop();
        k--;
    }

    while (!st.empty())
    {
        res = st.top() + res;
        st.pop();
    }

    cout << res;

    return 0;   
}