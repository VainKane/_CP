#include <bits/stdc++.h>

using namespace std;

string Bu1(int n)
{
    string res = "";

    stack<int> st;

    while (n / 2 != 0)
    {
        st.push(n % 2);
        n /= 2;
    }


    st.push(n % 2);

    while (!st.empty())
    {
        if (st.top() == 1)
        {
            res += '0';
        }
        else
        {
            res += '1';
        }

        st.pop();
    }

    return res;
}

int n;

int main()
{
    cin >> n;

    cout << Bu1(n);
}