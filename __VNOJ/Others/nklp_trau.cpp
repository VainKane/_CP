#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define all(v) v.begin(), v.end()

int const N = 1e5 + 5;

int n;
int a[N];

bool Check(vector<int> &v)
{
    sort(all(v));

    if (v[0] != 1) return false;
    FOR(i, 1, v.size() - 1) if (v[i] != v[i - 1] + 1) return false;

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    
    int res = 1;

    FOR(i, 1, n)
    {
        vector<int> v;
        FOR(j, i, n) 
        {
            v.push_back(a[j]);
            if (Check(v)) res = max(res, j - i + 1);
        }
    }

    cout << res;

    return 0;
}