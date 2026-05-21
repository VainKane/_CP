#include <bits/stdc++.h>

using namespace std;

int n;
int d;
pair<int, int> a[50009];

int l[50009];
int r[50009];
deque<int> q;

int res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> d;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    sort(a, a + n);

    for (int i = 0; i < n; i++)
    {
        while (!q.empty() && a[q.front()].first + d <= a[i].first)
        {
            q.pop_front();
        }
        while (!q.empty() && a[q.back()].second <= a[i].second)
        {
            q.pop_back();
        }
        q.push_back(i);

        l[i] = a[q.front()].second;
    }

    q = deque<int>();

    for (int i = n - 1; i >= 0; i--)
    {
        while (!q.empty() && a[q.front()].first - d >= a[i].first)
        {
            q.pop_front();
        }
        while (!q.empty() && a[q.back()].second <= a[i].second)
        {
            q.pop_back();
        }
        q.push_back(i);

        r[i] = a[q.front()].second;
    }

    for (int i = 1; i < n - 1; i++)
    {
        if (l[i - 1] >= 2 * a[i].second && r[i + 1] >= 2 * a[i].second) res++;
    }

    cout << res;

    return 0;
}