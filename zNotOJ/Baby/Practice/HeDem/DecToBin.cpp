#include <bits/stdc++.h>

using namespace std;

int n;

stack<int> st;
int r;

int main()
{
    cin >> n;

    while (n / 2 != 0)
    {
        r = n % 2;
        st.push(r);
        n /= 2;
    }

    st.push(n % 2);


    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
}