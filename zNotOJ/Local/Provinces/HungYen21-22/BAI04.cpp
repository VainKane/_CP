#include <bits/stdc++.h>

using namespace std;

#define name "BAI04"

int const N = 1e5 + 5;

int n;
int a[N];

int cnt1[N];
int cnt2[N];
int cnt3[N];

void Sub1()
{
    long long res = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if ((*max_element(a + i, a + j + 1) - *min_element(a + i, a + j + 1)) % 2 == 0) res++;
        }
    }

    cout << res;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    // if (n <= 4000) Sub1();
    // else Sub2();

    Sub2();

    return 0;
}