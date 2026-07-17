#include <bits/stdc++.h>

// bai nay hay

using namespace std;

int n;
int a[1000];

stack<int> st;
int b[1000];

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    for (int i = 0; i <= n; i++)
    {
        if (st.empty())
        {
            st.push(i);
        }

        if (a[i] < a[st.top()])
        {
            while (!st.empty() && a[i] < a[st.top()])
            {
                if (st.size() == 1)
                {
                    b[st.top()] = i * a[st.top()];
                    st.pop();
                    continue;
                }

                int valueIndex = st.top();
                st.pop();
                {
                    b[valueIndex] = (i - st.top() - 1) * a[valueIndex];
                }
            }

            st.push(i);
        }
        else if (i != st.top())
        {
            st.push(i);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << b[i] << ' ';
    }

    // luu y, cac pt cua mang b ko phai la dien tich lon nhat cua cac hinh chu nhat
    // coi phan tu mang a tuong ung la cot nho nhat trong truong hop co nhung cot bang nhau!!!
}