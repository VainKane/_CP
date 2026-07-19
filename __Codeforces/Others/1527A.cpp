#include <bits/stdc++.h>

#define bit(i, n) (n & (1 << i))

using namespace std;

int t;
int n;

int main()
{
    cin >> t;

    while (t--)
    {
        cin >> n;

        bitset<32> a (n);
        int pos;

        for (int i = 31; i >= 0; i--)
        {
            if (bit(i, n))
            {
                pos = i;
                break;
            }
        }

        cout << (1 << pos) - 1 << '\n';
    }
    
    return 0;
}