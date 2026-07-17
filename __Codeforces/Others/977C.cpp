#include <bits/stdc++.h>

using namespace std;

int Solve(int a[], int n, int k)
{
    sort(a, a + n);

    if (k == 0 && a[0] != 1) return a[0] - 1;

    if (k > 0)
    {
        if (a[k - 1] != a[k]) return a[k - 1];
    }
     
    return -1;
}

int n;
int k;

int a[(int)2e5 + 10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << Solve(a, n, k);

    return 0;
}