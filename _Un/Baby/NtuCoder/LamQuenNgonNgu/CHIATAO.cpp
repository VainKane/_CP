#include <bits/stdc++.h>

using namespace std;

bool Check(int light, int heavy)
{
    if (light % 2 == 0 && heavy % 2 == 0)
    {
        return true;
    }
    
    if (light % 2 == 1)
    {
        return false;
    }

    while (heavy > 0 && light > 0)
    {
        heavy -= 1;
        light -= 2;
    }

    if (heavy == 0 && light % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

    if (light == 0 && heavy % 2 == 0)
    { 
        return true;
    }
    else
    {
        return false;
    }
}

int n;

int light = 0;
int heavy = 0;

int weight;

int main()
{   
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> weight;

        if (weight == 100)
        {
            light += 1;
        }
        else
        {
            heavy += 1;
        }
    }

    if (Check(light, heavy))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}