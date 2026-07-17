#include <bits/stdc++.h>

#define min(a, b) ((a < b) ? a : b)
#define max(a, b) ((a > b) ? a : b)

using namespace std;

int t;

int a;
int b;
int c;

int main()
{
    cin >> t;

    while (t--)
    {
        cin >> a >> b >> c;

        int mi = min(min(a, b), c);
        int ma = max(max(a, b), c);

        int mid = a + b + c - (ma + mi);

        cout << ma - mid + mid - mi << '\n';
    }

    return 0;
}