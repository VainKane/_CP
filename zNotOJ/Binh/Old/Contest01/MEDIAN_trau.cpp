#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define name "MEDIAN"

int const N = 2e5 + 5;

int n, k;
int a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".ans", "w", stdout);

    auto starttime = chrono::high_resolution_clock::now();

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n - k + 1; i++)
    {
        vector<int> v;
        v.push_back(0);

        for (int j = i; j <= i + k - 1; j++) v.push_back(a[j]);
        sort(all(v));

        cout << v[(k + 1) / 2] << ' ';
    }

    auto endtime = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(endtime - starttime).count();
    cerr << "\nRuntime: " << duration << "ms\n";

    return 0;
}