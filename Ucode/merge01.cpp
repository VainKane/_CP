#include <bits/stdc++.h> 

using namespace std;

int const N = 1e5 + 5;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int n;
int a[N];
int tmp[N];

long long Sort(int l, int r)
{
    if (l == r) return 0;

    int mid = (l + r) >> 1;

    long long res = Sort(l, mid) + Sort(mid + 1, r);

    int i = l - 1;
    int j = mid;

    FOR(k, l, r)
    {
        if (j >= r || (i < mid && a[i + 1] <= a[j + 1])) tmp[k] = a[++i];
        else
        {
            if (a[j + 1] < a[i + 1]) res += mid - i;
            tmp[k] = a[++j];
        }
    }

    FOR(i, l, r) a[i] = tmp[i];
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    cout << Sort(1, n) << '\n';
    // FOR(i, 1, n) cout << a[i] << ' ';

    return 0;
}