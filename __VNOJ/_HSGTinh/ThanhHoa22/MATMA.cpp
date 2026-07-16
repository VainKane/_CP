#include <bits/stdc++.h>

using namespace std;

string n;

int sum = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("MATMA.INP", "r", stdin);
    freopen("MATMA.OUT", "w", stdout);

    cin >> n;

    sort(n.begin(), n.end(), greater<char>());

    for (char num : n)
    {
        sum += num - '0';
    }

    if (sum % 3 != 0 || *n.rbegin() != '0') cout << -1;
    else cout << n;

    return 0;
}