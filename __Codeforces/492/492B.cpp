#include <bits/stdc++.h>

#define max(a, b) ((a > b) ? a : b)

using namespace std;

int n;
int l;

int a[1009];
int d[1009];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cout << fixed << setprecision(10);

    cin >> n >> l;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    d[0] = a[0];

    for (int i = 1; i < n; i++)
    {
        d[i] = a[i] - a[i - 1];
    }

    cout << max((long double)l - a[n - 1], max((long double)d[0], (long double)*max_element(d, d + n) / 2));

    return 0;
}