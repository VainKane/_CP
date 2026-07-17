#include <bits/stdc++.h>

using namespace std;

int a;
int b;
int c;

int t;

int main()
{
    cin >> t;

    while (t--)
    {
        cin >> a >> b >> c;

        cout << (a ^ b ^ c) << '\n';
    }

    return 0;
}