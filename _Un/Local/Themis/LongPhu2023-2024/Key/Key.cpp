#include <bits/stdc++.h>

using namespace std;

int Reverse(int n)
{
    int res = 0;

    while (n)
    {
        res *= 10;
        res += n % 10;
        n /= 10;
    }

    return res;
}

string str = "";
int num = 0;

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (str.length() < 100)
    {
        num++;
        int a = Reverse(num);

        while (a)
        {
            str += (char)((a % 10) + '0');
            a /= 10;
        }

        if (num % 10 == 0)
        {
            str += '0';
        }
    }

    cin >> n;

    while (n--)
    {
        int pos;
        cin >> pos;
        cout << str[pos - 1];
    }
    return 0;
}
