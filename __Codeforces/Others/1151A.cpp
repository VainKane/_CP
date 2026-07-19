#include <bits/stdc++.h>

using namespace std;

int Cost(char cur, char tar)
{
    return min(min(abs(cur - tar), 'Z' - cur + 1 + tar - 'A'), cur - 'A' + 1 + 'Z' - tar);
}

int n;
string s;

int res = INT_MAX;

int main()
{
    cin >> n;
    cin >> s;

    for (int i = 0; i <= n - 4; i++)
    {
        int cost = 0;

        cost += Cost(s[i], 'A');
        cost += Cost(s[i + 1], 'C');
        cost += Cost(s[i + 2], 'T');
        cost += Cost(s[i + 3], 'G');

        res = min(res, cost);
    }

    cout << res;

    return 0;
}