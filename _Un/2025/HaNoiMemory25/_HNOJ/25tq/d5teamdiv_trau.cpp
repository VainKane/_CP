#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define BIT(i, x) (((x) >> (i)) & 1)
#define MK(i) (1ll << (i))

int const N = 22;

int n;
long long a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        cin >> n;
        REP(i, n) cin >> a[i];

        REP(mask, MK(n))
        {
            vector<int> v1, v2;

            REP(i, n) 
            {
                if (BIT(i, mask)) v1.push_back(i);
                else v2.push_back(i);
            }
            
            
        }
    }

    return 0;
}