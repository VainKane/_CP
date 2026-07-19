#include <bits/stdc++.h>

using namespace std;

int n;

int count1[31];

int res = 0;
char key;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char chr;

        cin >> chr;

        int count = count1[chr - 'a'] += 1;

        if (count > res)
        {
            res = count;
            key = chr;
        }
        else if (count == res)
        {
            if (chr < key)
            {
                key = chr;
            }
        }
    }

    cout << key;
}