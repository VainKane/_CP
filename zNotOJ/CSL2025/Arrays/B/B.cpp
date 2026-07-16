#include <bits/stdc++.h>

using namespace std;

int n;
int q;
int l;
int r;

long long pre[(int)1e5 + 10];
int value;

int main()
{
    cin >> n;

    cin >> pre[0];

    for (int i = 1; i < n; i++)
    {
        cin >> value;

        pre[i] = pre[i - 1] + value;
    }

    cin >> q;

    for (int i = 0; i < q; i++)
    {
        cin >> l >> r;
        cout << pre[r - 1] - pre[l - 2] << '\n';
    }

    return 0;
}
