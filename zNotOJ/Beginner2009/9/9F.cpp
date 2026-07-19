#include <bits/stdc++.h>

using namespace std;

int n;
int m;
long long k;

int a[1009];
int b[1009];

vector<int> c;
vector<int> d;
vector<long long> pre;

long long Greater(int x, long long &sum)
{
    long long res = 0;
    sum = 0;

    int i = 0;
    int j = d.size() - 1;

    while (i < c.size() && j >= 0)
    {
        int s = c[i] + d[j];

        if (s > x)
        {
            res += 1ll * c.size() - i;

            sum += pre[i] + (c.size() - i) * d[j];
            
            j--;
        }
        else i++;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c.push_back(a[i] + a[j]);
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            d.push_back(b[i] + b[j]);
        }
    }

    sort(c.begin(), c.end());
    sort(d.begin(), d.end());

    pre.resize(c.size());
    *pre.rbegin() = *c.rbegin();

    for (int i = c.size() - 2; i >= 0; i--)
    {
        pre[i] = pre[i + 1] + c[i];
    }

    int l = 0;
    int r = 4e6;
    long long x;
    long long res;

    while (l <= r)
    {
        long long mid = l + (r - l) / 2;

        if (Greater(mid, res) < k)
        {
            x = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    long long a = Greater(x, res);
    cout << res + (k - a) * x;

    return 0;
} 