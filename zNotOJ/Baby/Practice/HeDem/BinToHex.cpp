#include <bits/stdc++.h>   

using namespace std;



long long BinPow(int a, int b)
{
    long long res = 1;
    if (b == 0)
    {
        return 1;
    }

    while (b)
    {
        if (b % 2 == 1)
        {
            res *= a;
        }

        b /= 2;
        a *= a;
    }

    return res;
}

string DecToHex(int n)
{
    stack<int> st;
    string res = "";
    int r;

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
            res += 'A';
            st.pop();
        }
        else if (st.top() == 11)
        {
            res += 'B';
            st.pop();

        }
        else if (st.top() == 12)
        {
            res += 'C';
            st.pop();

        }
        else if (st.top() == 13)
        {
            res += 'D';
            st.pop();

        }
        else if (st.top() == 14)
        {
            res += 'E';
            st.pop();

        }
        else if (st.top() == 15)
        {
            res += 'F';
            st.pop();

        }
        else{
            res += (char)(st.top() + '0');
            st.pop();

        }
    }

    return res;
}

int BinToDec(string n)
{
    int soMu;
    int res = 0;

    int length = n.length() - 1;

    for (int i = 0; i < n.length(); i++)
    {
        int num = n[i] - '0';
        soMu = length - i;

        res += num * BinPow(2, soMu);
    }

    return res;
}

string n;



int main()
{
    getline(cin, n);
    
    cout << DecToHex(BinToDec(n));
}