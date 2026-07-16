#include <bits/stdc++.h>

using namespace std;

int a;
int b;
int c;
int d;
int e;

int count1 = 0;

int main()
{
    cin >> a >> b >> c >> d >> e;

    if (a != b)
    {
        count1 += 1;
    }
    if (a != c)
    {
        count1 += 1;
    }
    if (a != d)
    {
        count1 += 1;
    }
    if (a != e)
    {
        count1 += 1;
    }

    if (count1 > 1)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }
}