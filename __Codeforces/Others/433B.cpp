#include <bits/stdc++.h>

using namespace std;

int n;
int v[(int)1e5 + 10];
long long pre[(int)1e5 + 10];
long long sortPre[(int)1e5 + 10];

int m;
int l;
int r;

int type;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        pre[0] = v[0];

        if (i >= 1) pre[i] = pre[i - 1] + v[i];
    }

    sort(v, v + n);

    sortPre[0] = v[0];

    for (int i = 1; i < n; i++)
    {
        sortPre[i] = sortPre[i - 1] + v[i];
    }

    cin >> m;

    while (m--)
    {
        cin >> type >> l >> r;
        l--; r--;

        if (type == 1)
        {   
            cout << pre[r] - pre[l - 1] << '\n';
        }
        else
        {
            cout << sortPre[r] - sortPre[l - 1] << '\n';
        }
    }

    return 0;
}