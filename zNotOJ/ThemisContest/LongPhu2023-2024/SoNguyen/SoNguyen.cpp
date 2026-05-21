#include <bits/stdc++.h>

using namespace std;

string n;
int sum = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (char num : n)
    {
        sum += num - '0';
    }

    cout << sum;

    return 0;
}
