#include <bits/stdc++.h>

using namespace std;

int Count(int x)
{
    int res = 0;
    
    while (x)
    {
        res += x % 10;
        x /= 10;
    }

    return res;
}

int k;
int x = 0, cnt = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> k;
    while (cnt < k) cnt += (Count(++x) == 10);
    cout << x;

    return 0;
}