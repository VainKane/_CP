#include <bits/stdc++.h>

#define max(a, b) ((a > b) ? a : b)

using namespace std;

int xPos1;
int yPos1;
int xPos2;
int yPos2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("ROBOT.INP", "r", stdin);
    freopen("ROBOT.OUT", "w", stdout);

    cin >> xPos1 >> yPos1;
    cin >> xPos2 >> yPos2;

    cout << max(abs(xPos1 - xPos2), abs(yPos1 - yPos2));

    return 0;
}