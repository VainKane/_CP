#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

int const N = 1e5 + 5;

int n, m;
vector<int> a;

int f[N];
int cnt[N];



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, n) 
    {
        int x; cin >> x;
        cnt[x]++;
    }

    return 0;
}