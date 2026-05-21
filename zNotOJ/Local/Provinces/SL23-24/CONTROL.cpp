#include <bits/stdc++.h>

using namespace std;

string s;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int Direct(char ch)
{
    if (ch == 'U') return 0;
    else if (ch == 'L') return 1;
    else if (ch == 'D') return 2;
    return 3;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;
    int x = 0;
    int y = 0;

    for (auto ch : s)
    {
        // cout << x << ' ' << y << '\n';

        int d = Direct(ch);
        x = x + dx[d];
        y = y + dy[d];

    }

    cout << x << ' ' << y;

    return 0;
}