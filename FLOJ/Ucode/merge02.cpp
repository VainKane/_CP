#include <bits/stdc++.h> 

using namespace std;

int const N = 2e5 + 5;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int n;
long long t;

long long pre[N];

long long Solve(int l, int r)
{
    if (l == r) return pre[r] - pre[l - 1] < t;

    int mid = (l + r) >> 1;

    long long res = Solve(l, mid) + Solve(mid + 1, r);
    int j = mid;
    
    FOR(i, l, mid)
    {
        while (j < r && pre[j + 1] - pre[i - 1] < t) j++;
        res += j - mid;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> t;
    FOR(i, 1, n) 
    {
        int x; cin >> x;
        pre[i] = pre[i - 1] + x;
    }

    cout << Solve(1, n) << '\n';

    return 0;
}