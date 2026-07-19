#include <bits/stdc++.h>

using namespace std;

int a;
int b;
int c;
int d;
int e;

int min1;
int secMin;

int main()
{
    cin >> a >> b >> c >> d >> e;

    min1 = secMin = a;

    if (min1 > b)
    {
        secMin = min1;
        min1 = b;
    }
    if (min1 > c)
    {
        secMin = min1;
        min1 = c;
    }
    if (min1 > d)
    {
        secMin = min1;
        min1 = d;
    }
    if (min1 > e)
    {
        secMin = min1;
        min1 = e;
    }
    
    if (secMin == a)
    {
        secMin = b;

        if (secMin > c)
        {
            secMin = c;
        }
        if (secMin > d)
        {
            secMin = d;
        }
        if (secMin > e)
        {
            secMin = e;
        }
    }

    cout << secMin;
}