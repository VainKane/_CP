#include <bits/stdc++.h>

using namespace std;

string str;
long long sum = 0;

int main()
{
    getline(cin, str);

    for (char value : str)
    {
        sum += value - '0';
    }

    cout << sum;
}