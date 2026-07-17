#include <bits/stdc++.h>   

using namespace std;

string n;

int soMu;
int res = 0;

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

int main()
{
    getline(cin, n);
    
    int length = n.length() - 1;

    for (int i = 0; i < n.length(); i++)
    {
        int num = n[i] - '0';
        soMu = length - i;

        res += num * BinPow(2, soMu);
    }

    cout << res;
}