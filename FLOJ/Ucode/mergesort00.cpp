#include <bits/stdc++.h> 

using namespace std;

int const N = 2e5 + 5;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int n;
int a[N];
int tmp[N];

void Sort(int l, int r)
{
    if (l == r) return;

    int mid = (l + r) >> 1;

    Sort(l, mid);
    Sort(mid + 1, r);

    int i = l - 1;
    int j = mid;

    // inplace_merge(a + l, a + mid + 1, a + r + 1);

    FOR(k, l, r)
        tmp[k] = ((j + 1 > r || (i + 1 <= mid && a[i + 1] < a[j + 1])) ? a[++i] : a[++j]);

    FOR(i, l, r) a[i] = tmp[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    Sort(1, n);
    FOR(i, 1, n) cout << a[i] << ' ';

    return 0;
}