#include <bits/stdc++.h>

using namespace std;

int const N = 20;

int a[N];
int x[N];
int n;

bool Check()
{
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != x[i]) return false;
    }
    return true;
}

void Query1()
{
    int cnt = 0;
    int res;
    do
    {
        cnt++;
        if (Check()) res = cnt;
    } while (next_permutation(a + 1, a + n + 1));

    cout << res << '\n';
}

void Query2(int k)
{
    int cnt = 0;
    do
    {
        cnt++;
        if (cnt == k) 
        {
            for (int i = 1; i <= n; i++) cout << a[i] << ' ';
            cout << '\n';
        }
    } while (next_permutation(a + 1, a + n + 1));
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) a[i] = i;

    int q;
    while (cin >> q)
    {
        if (q == 1)
        {
            for (int i = 1; i <= n; i++) cin >> x[i];
            Query1();
        }
        else 
        {
            int k; cin >> k;
            Query2(k);
        }
    }  

    return 0;
}