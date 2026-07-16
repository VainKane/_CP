#include <bits/stdc++.h>

using namespace std;

int a;
int b;
int c;
int d;

int min1;

int main()
{
    cin >> a >> b >> c >> d;

    min1 = a;

    if (min1 > b)
    {
        min1 = b;
    }
    if (min1 > c)
    {
        min1 = c;
    }
    if (min1 > d)
    {
        min1 = d;
    }

    cout << min1;
}