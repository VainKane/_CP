#include <iostream>
using namespace std;
const int MAXN = 1005;
int n, s;
int a[MAXN];
bool check(int x)
{
    int sum = 0, cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (sum + a[i] > x)
        {
            cnt++;
            sum = a[i];
        }
        else
        {
            sum += a[i];
        }
    }
    return cnt <= s;
}
int main()
{
    freopen("12F.inp", "r", stdin);
    freopen("12F.ans", "w", stdout);

    cin >> n >> s;
    int l = 0, r = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        r += a[i];
        l = max(l, a[i]);
    }
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << l << endl;
    return 0;
}