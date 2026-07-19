#include <bits/stdc++.h>

#define min(a, b) ((a < b) ? a : b)

using namespace std;

int n;
int m;

int a[109];
int b[109];

int cnta[109];
int cntb[109];

int res = 0;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnta[a[i]]++;
    }

    cin >> m;
    
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        cntb[b[i]]++;
    }

    sort(a, a + n);
    sort(b, b + m);

    for (int i = 0; i < n; i++)
    {
        int add = min(cnta[a[i]], cntb[a[i] - 1] + cntb[a[i]] + cntb[a[i] + 1]);
        res += add;
        cnta[a[i]] -= add;
            
        int minus = min(cntb[a[i] - 1], add);
        cntb[a[i] - 1] -= minus;
        add -= minus;

        minus = min(cntb[a[i]], add);
        cntb[a[i]] -= minus;
        add -= minus;

        minus = min(cntb[a[i] + 1], add);
        cntb[a[i] + 1] -= minus;
        add -= minus;

    }

    cout << res;

    return 0;
}