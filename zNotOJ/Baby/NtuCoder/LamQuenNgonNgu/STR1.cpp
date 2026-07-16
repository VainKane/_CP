#include <bits/stdc++.h>

using namespace std;

int Sum(string str)
{
    int sum = 0;

    for (char value : str)
    {
        sum += value - '0';
    }

    return sum;
}

string str;

int main()
{
    getline(cin, str);

    cout << Sum(str);
}