#include <bits/stdc++.h>

using namespace std;

int n;
int count1 = 0;


int main()
{   
    cin >> n;

    for (int i = n; i > 0; i--)
    {
        count1 += 1;

        if (count1 > 3)
        {
            i = -1;
        }

        for (int j = 0; j < i; j++)
        {
            cout << '#';
        }      

        cout << '\n';
    }
}