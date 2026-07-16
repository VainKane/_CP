#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()

int const N = 1e5 + 5;

int n, k;
int a[N];
long long pre[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i], pre[i] = pre[i - 1] + a[i];
    
    vector<long long> b;
    FOR(i, 1, n) FOR(j, i, n) b.push_back(pre[j] - pre[i - 1]);
    
    sort(all(b), greater<long long> ());
    cout << b[k - 1];

    return 0;
}