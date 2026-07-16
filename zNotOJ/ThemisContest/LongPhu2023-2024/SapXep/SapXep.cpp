#include <bits/stdc++.h>

using namespace std;

int n;

int odd[19];
int even[19];

int cnt1 = 0;
int cnt2 = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;

        if (value % 2 == 0)
        {
            even[cnt2] = value;
            cnt2++;
        }
        else
        {
            odd[cnt1] = value;
            cnt1++;
        }
    }

    sort(even, even + cnt2);
    sort(odd, odd + cnt1);

    for (int i = 0; i < cnt2; i++)
    {
        cout << even[i] << ' ';
    }

    for (int i = cnt1 - 1; i >= 0; i--)
    {
        cout << odd[i] << ' ';
    }

    return 0;
}
