#include <bits/stdc++.h>

using namespace std;

int n;
int m;

int cnt[10];

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m + n; i++)
    {
        int value;
        cin >> value;

        cnt[value]++;
    }

    for (int i = 1; i <= 4; i++)
    {
        cout << cnt[i] << ' ';
    }

    cout << '\n';

    int s = m + n;
    int p4 = cnt[4] / 2;
    int p = p4 + ((s - cnt[4]) / 2);

    cout << p << '\n';
    cout << s - (p * 2);

    return 0;
}
