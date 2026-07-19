#include <bits/stdc++.h>

using namespace std;

int n;

int candies = 0;
int packets = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("CANDIES.INP", "r", stdin);
    freopen("CANDIES.OUT", "w", stdout);

    cin >> n;

    while (n--)
    {
        int val;
        cin >> val;

        if (val % 3 == 0 && val > 0)
        {
            packets++;
            candies += val;
        }
    }

    candies -= packets * 3;

    cout << packets << '\n' << candies / 3;
    
    return 0;
}