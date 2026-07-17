#include <bits/stdc++.h>

using namespace std;

int BinPow(int a, int b)
{
    int res = 1;

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

int HexToDec(string hex)
{
    int res = 0;
    int num;
    int length = hex.length();
    int soMu;

    for (int i = 0; i < length; i++)
    {
        if (hex[i] == 'A')
        {
            hex[i] = 10;
        }
        else if (hex[i] == 'B')
        {
            hex[i] = '11';
        }
        num = hex[i] - '0';
        soMu = length - 1 - i;

        cout << num << ' ';

        res += num * BinPow(16, soMu);
    }
    
    return res;
}

string hexNum;

int main()
{
    getline(cin, hexNum);

    cout << HexToDec(hexNum); 
}