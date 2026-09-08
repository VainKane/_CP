#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()

int const N = 1e5 + 5;

int n, m;
vector<int> s[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i, 1, m)
    {
        int k; cin >> k;
        while (k--)
        {
            int x; cin >> x;
            s[i].push_back(x);
        }

        sort(all(s[i]));
        s[i].erase(unique(all(s[i])), s[i].end());
    }

    int q; cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        
        long long res = 0;
        FOR(i, 1, m) res += i * (binary_search(all(s[i]), x) && binary_search(all(s[i]), y));
        cout << res << '\n';
    }

    return 0;
}