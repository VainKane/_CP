#include <bits/stdc++.h>

using namespace std;

int n;

stack<int> st;

int r;

int main()
{
    cin >> n;


    while (n / 16 != 0)
    {
        r = n % 16;
        st.push(r);
        n /= 16;


    }

    st.push(n % 16);

    while (!st.empty())
    {
        if (st.top() == 10)
        {
            cout << 'A';
            st.pop();
        }
        else if (st.top() == 11)
        {
            cout << 'B';
            st.pop();

        }
        else if (st.top() == 12)
        {
            cout << 'C';
            st.pop();

        }
        else if (st.top() == 13)
        {
            cout << 'D';
            st.pop();

        }
        else if (st.top() == 14)
        {
            cout << 'E';
            st.pop();

        }
        else if (st.top() == 15)
        {
            cout << 'F';
            st.pop();

        }
        else{
            cout << st.top();
            st.pop();

        }
    }

    return 0;
}