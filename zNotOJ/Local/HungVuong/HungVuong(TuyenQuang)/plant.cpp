#include <bits/stdc++.h>

using namespace std;

struct Square
{
    int a, b, c;

    bool operator < (Square other)
    {
        return b - c > other.b - other.c;
    }
}; 

int const N = 1e5 + 5;

int n;
int x, y, z;

Square pos[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> x >> y >> z;
    n = x + y + z;

    for (int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        pos[i] = {a, b, c};
    }

    sort(pos + 1, pos + n + 1);

    for (int k = y; k <= n - z; k++)
    {
        
    }

    return 0;
}