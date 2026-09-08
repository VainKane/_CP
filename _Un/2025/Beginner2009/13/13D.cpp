#include <bits/stdc++.h>

using namespace std;

int n;
int k;

int a[(int)5e6 + 10];
int b[(int)5e6 + 10];
vector<int> c;
deque<int> q;

int res = INT_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (int i = 1; i < n; i++) b[i - 1] = a[i] - a[i - 1];

    int d = n - k;

    for (int i = 0; i < d - 1; i++)
    {
        while (!q.empty() && b[q.back()] >= b[i])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    c.push_back(b[q.front()]);

    for (int i = d - 1; i < n - 1; i++)
    {
        if (q.front() + d - 1 <= i)
        {
            q.pop_front();
        }
        while (!q.empty() && b[q.back()] >= b[i])
        {
            q.pop_back();
        }
        q.push_back(i);
        c.push_back(b[q.front()]);
    }

    for (int i = d - 1; i < n; i++)
    {
        res = min(res, a[i] - a[i - d + 1] + c[i - d + 1]);
    }

    cout << res;

    return 0;
}