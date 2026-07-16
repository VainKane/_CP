#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define F first
#define S second
#define all(v) v.begin(), v.end()

int const N = 1e5 + 5;

int n, k;
int a[N], b[N];

vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.S > b.S;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];

    long long res = 0;
    FOR(i, 1, n) res += 1ll * a[i] * b[i];


    return 0;
}