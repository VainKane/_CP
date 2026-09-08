#include <bits/stdc++.h>

using namespace std;

void Go(int d, int &x, int &y)
{
    if (d == 0)
        y++;
    else if (d == 1)
        x++;
    else if (d == 2)
        y--;
    else if (d == 3)
        x--;
}

int n;
string s;

int x = 0;
int y = 0;

int d = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> s;

    for (char chr : s)
    {
        if (chr == 'G')
        {
            Go(d, x, y);
        }
        else if (chr == 'L')
        {
            d -= 1;
            if (d < 0) d = 3;
            Go(d, x, y);
        }
        else if (chr == 'R')
        {
            d = (d + 1) % 4;
            Go(d, x, y);
        }
        else if (chr == 'B')
        {
            d = (d + 2) % 4;
            Go(d, x, y);
        }
    }

    cout << x << ' ' << y;

    return 0;
}