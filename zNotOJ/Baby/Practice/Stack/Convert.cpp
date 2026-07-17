#include <bits/stdc++.h>

using namespace std;

int n;
stack<int> st;

int main()
{
    cin >> n;

    while (n)
    {
        st.push(n % 2);
        n /= 2;
    }

    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
}