#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define name "CSBN"

int const N = 1e7 + 5;

int n;
int a[N];
vector<int> b;

long long p[N];
long long res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b.push_back(a[i]);
    }

    sort(all(b));
    b.erase(unique(all(b)), b.end());

    for (int i = 1; i <= n; i++) a[i] = lower_bound(all(b), a[i]) - b.begin() + 1;

    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) p[i] = p[i - 1] + i; 

    int pre = 1;
    int l = 1;
    for (int i = 2; i <= n + 1; i++)
    {
        if (a[i] == a[i - 1]) 
        {
            l++;
            continue;
        }

        res += p[l - 1];

        pre = a[i];
        l = 1;
    }

    cout << res;

    return 0;
}