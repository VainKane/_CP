#include <bits/stdc++.h>

using namespace std;

string n;
int sum = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n.length(); i++)
    {
        sum += n[i] - '0';
    }

    cout << sum;

    return 0;
}
