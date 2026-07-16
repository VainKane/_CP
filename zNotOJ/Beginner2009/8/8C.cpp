#include <bits/stdc++.h>

using namespace std;

int n;
int m;

int l[(int)1e5 + 10];
int r[(int)1e5 + 10];

int Solve(int a, int b, int k)
{
    if (a > b)
    {
        return 0;
    }
    else if (a == b && a != n)
    {
        return l[a] - k;
    }
    else return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i];
    }

    sort(l, l + n);
    sort(r, r + n);

    while (m--)
    {
        int k;
        cin >> k;

        int a = upper_bound(l, l + n, k) - l;
        int b = upper_bound(r, r + n, k) - r;

        cout << Solve(a, b, k) << '\n';
    }
    

    return 0;
}